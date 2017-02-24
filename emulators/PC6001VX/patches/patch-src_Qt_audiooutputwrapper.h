$NetBSD: patch-src_Qt_audiooutputwrapper.h,v 1.1 2017/02/24 17:33:32 tsutsui Exp $

- pull upstream changes to make QAudioOutput calls thread safe

--- src/Qt/audiooutputwrapper.h.orig	2017-02-21 14:44:21.000000000 +0000
+++ src/Qt/audiooutputwrapper.h
@@ -0,0 +1,35 @@
+#ifndef AUDIOOUTPUTWRAPPER_H
+#define AUDIOOUTPUTWRAPPER_H
+#ifndef NOSOUND
+#include <QObject>
+#include <QPointer>
+#include <QAudioOutput>
+
+// QAudioOutputのラッパークラス。
+// P6Vのコードではサウンド制御が複数のスレッドから呼ばれるが、
+// Qtの規約により実処理はオブジェクトの所属スレッドで実施する必要があるため
+// サウンド制御の諸APIをinvokeMethod経由で呼べるようSLOTにする。
+class AudioOutputWrapper : public QObject
+{
+    Q_OBJECT
+public:
+    explicit AudioOutputWrapper(const QAudioDeviceInfo& info,
+                                const QAudioFormat& format, QObject* parent = NULL)
+        : QObject(parent)
+        , AudioOutput(new QAudioOutput(info, format, this)) {}
+
+public slots:
+    // 下記のメソッドはinvokeMethodから呼ぶこと。
+    QPointer<QIODevice> start() { return AudioOutput->start(); }
+    void suspend() { AudioOutput->suspend(); }
+    void resume() { AudioOutput->resume(); }
+    void stop() { AudioOutput->stop(); }
+
+public:
+    QAudio::State state() const { return AudioOutput->state(); }
+
+private:
+    QAudioOutput* AudioOutput;
+};
+#endif // NOSOUND
+#endif // AUDIOOUTPUTWRAPPER_H
