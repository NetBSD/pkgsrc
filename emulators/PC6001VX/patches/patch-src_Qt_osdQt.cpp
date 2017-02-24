$NetBSD: patch-src_Qt_osdQt.cpp,v 1.1 2017/02/24 17:33:32 tsutsui Exp $

- pull upstream changes:
 - fix a missed comment for FDD access wait
 - make QAudioOutput calls thread safe

--- src/Qt/osdQt.cpp.orig	2016-08-27 12:19:26.000000000 +0000
+++ src/Qt/osdQt.cpp
@@ -46,8 +46,9 @@ QVector<QRgb> PaletteTable;             
 
 #ifndef NOSOUND
 //サウンド関連
+#include "audiooutputwrapper.h"
 QPointer<QIODevice> audioBuffer = NULL;
-QPointer<QAudioOutput> audioOutput = NULL;
+QPointer<AudioOutputWrapper> audioOutput = NULL;
 #endif
 
 //ジョイスティック関連
@@ -256,6 +257,7 @@ const char *MsgIni[] = {
 	QT_TRANSLATE_NOOP("PC6001VX", "オーバークロック率 (1-1000)%"),
 	QT_TRANSLATE_NOOP("PC6001VX", "CRCチェック Yes:有効 No:無効"),
 	QT_TRANSLATE_NOOP("PC6001VX", "ROMパッチ Yes:あてる No:あてない"),
+	QT_TRANSLATE_NOOP("PC6001VX", "FDDアクセスウェイト Yes:有効 No:無効"),
 	// [DISPLAY]
 	QT_TRANSLATE_NOOP("PC6001VX", "MODE4カラーモード 0:モノクロ 1:赤/青 2:青/赤 3:ピンク/緑 4:緑/ピンク"),
 	QT_TRANSLATE_NOOP("PC6001VX", "スキャンライン Yes:あり No:なし"),
@@ -1532,7 +1534,7 @@ bool OSD_OpenAudio( void *obj, CBF_SND c
 		format = info.nearestFormat(format);
 	}
 
-	audioOutput = new QAudioOutput(info, format);
+    audioOutput = new AudioOutputWrapper(info, format);
 	//#PENDING これではグローバルボリュームを変えてしまう？
 	//audioOutput->setVolume(0.5);
 
@@ -1553,7 +1555,7 @@ void OSD_CloseAudio( void )
 {
 #ifndef NOSOUND
 	if(audioOutput){
-		audioOutput->stop();
+        QMetaObject::invokeMethod(audioOutput, "stop");
 	}
 #endif
 }
@@ -1570,9 +1572,13 @@ void OSD_StartAudio( void )
 #ifndef NOSOUND
 	if(audioOutput){
 		if(audioOutput->state() == QAudio::SuspendedState){
-			audioOutput->resume();
+            QMetaObject::invokeMethod(audioOutput, "resume");
 		} else {
-			audioBuffer = audioOutput->start();
+			//呼び元スレッドによってコネクションタイプを変える(戻り値を取得できるようにするために必要)
+			Qt::ConnectionType cType = QThread::currentThread() == qApp->thread() ?
+						Qt::DirectConnection : Qt::BlockingQueuedConnection;
+			QMetaObject::invokeMethod(audioOutput, "start", cType,
+                                      Q_RETURN_ARG(QPointer<QIODevice>, audioBuffer));
 		}
 	}
 #endif
@@ -1589,7 +1595,7 @@ void OSD_StopAudio( void )
 {
 #ifndef NOSOUND
 	if(audioOutput){
-		audioOutput->suspend();
+        QMetaObject::invokeMethod(audioOutput, "suspend");
 	}
 #endif
 }
