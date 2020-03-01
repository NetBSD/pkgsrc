$NetBSD: patch-TOOLS_mencvcd.sh,v 1.1 2020/03/01 11:50:24 wiz Exp $

Historic patch, not all parts clear.

Some are just more quoting.

--- TOOLS/mencvcd.sh.orig	2011-01-31 15:45:46.000000000 +0000
+++ TOOLS/mencvcd.sh
@@ -22,7 +22,7 @@ for exe in mplayer mpeg2enc mp2enc mplex
 		exit 1
 	fi
 done
-for exe in vcdimager lame cdrdao yuvdenoise sox toolame normalize; do
+for exe in vcdimager lame cdrdao sox toolame normalize; do
         if [ -z "`which $exe`" ]; then
                 echo "WARNING: $exe is not found in your path $PATH!"
 	fi
@@ -80,9 +80,6 @@ done
 
 TMPDIR="." # path to directory for creating temporary files, recommended 2-3GB space
 
-CDDRV="generic-mmc"    # cdrdao: cdwriter driver
-CDDEV="--device 0,1,0" # or comment out and create link /dev/cdrecorder
-                       # to your cdwriter dev
 CDMAXSIZE=800
 
 ################################################################################
@@ -120,6 +117,7 @@ usage() {
    echo "-noburn         disables burning."
    echo "-normalize      use 'normalize'."
    echo "-overburn       enables overburning a cd."
+   echo "-qmat <name>    quantisation matrix for mpeg2enc"
    echo "-pulldown       enable pulldown mode in output."
    echo "-ratio <s>      output ratio size of frames, see yuvscaler (1)."
    echo "-size <X>x<Y>   sets output size of frames."
@@ -179,7 +177,7 @@ case $1 in
       exit 1
    ;;
    *)
-      NAME=$1
+      NAME="$1"
       shift 1
    ;;
 esac
@@ -208,9 +206,9 @@ abrset=0
 asr=44100
 vbr=1152
 vbrset=0
-denoise="cat -"
+denoise=""
 vnorm="VCD"
-mplexnorm="-f $VCDMODE -m 1 -V -b 46"
+mplexnorm="-f $VCDMODE -V -b 46"
 imaget="-t vcd2"
 yuvin=""
 framerate=""
@@ -229,6 +227,7 @@ while [ "$1"x != "x" ]; do
 	shift 1
         ;;
       -w)
+qmat="-K kvcd"
       	wide="-M WIDE2STD"
 	;;
       -h|-?)
@@ -289,12 +288,16 @@ while [ "$1"x != "x" ]; do
 	shift 1
 	;;
       -denoise)
-        denoise="yuvdenoise"
+        denoise="-vf denoise3d"
         ;;
       -ratio)
         ratio=$2
         shift 1
         ;;
+      -qmat)
+        qmat="-K $2"
+        shift 1
+        ;;
       -sid) # mplayer option: have to set vf expand, too!!!
         sub="-vf pp,expand=-1:-1:-1:-1:1 -sid $2"
         shift 1
@@ -332,7 +335,7 @@ done
 mpegnorm="-f $VCDMODE -b $vbr -B 260 -V 46"
 if [ "$vnorm" = "SVCD" ]; then
    [ $vbrset -eq 0 ] && vbr=2500
-   mplexnorm="-f $SVCDMODE -m 2 -V -b 230"
+   mplexnorm="-f $SVCDMODE -V -b 230"
    mpegnorm="-f $SVCDMODE -b $vbr -B 260 -V 230"
    imaget="-t svcd"
 fi
@@ -361,10 +364,9 @@ if [ $burnonly -eq 0 ]; then
       $command &
 
       # mjpegtools
-      ($denoise < $VIDEO | \
-         yuvscaler -v 0 $wide -O $vnorm $size $yuvin | \
-         mpeg2enc -v 0 -s $mpegnorm $aratio -S $CDMAXSIZE -g 6 -G 15 -r 16 \
-	          $pd $framerate $yuvin -4 2 -2 1 -o $NAME.mpv) &
+      (yuvscaler -v 0 $wide -O $vcdnorm $size $active $tvnorm < $VIDEO |
+         mpeg2enc -v 0 $qmat -s $mpegnorm $aratio -S $CDMAXSIZE -g 6 -G 15 \
+	          -r 16 $pd $framerate $tvnorm -4 2 -2 1 -o "$NAME.mpv") &
 
       # wait for finishing the subprocesses
       wait
@@ -375,23 +377,23 @@ if [ $burnonly -eq 0 ]; then
       # do resampling with sox
       if [ $sox -ne 0 ]; then
 	echo "wait, do resampling with sox..."
-	sox $AUDIO -v $volume -r $asr $NAME.wav resample -qs
-	mv -f $NAME.wav $AUDIO
+	sox $AUDIO -v $volume -r $asr "$NAME.wav" resample -qs
+	mv -f "$NAME.wav" $AUDIO
       fi
 
       if [ $toolame -ne 0 -a $mp3 -eq 0 ]; then
 	# do mp2 encoding with toolame
 	echo "wait, encoding to mp2 audio with toolame..."
 	toolame -b $abr $AUDIO
-	mv -f `basename $AUDIO .wav`.mp2 $NAME.mpa
+	mv -f `basename $AUDIO .wav`.mp2 "$NAME.mpa"
       elif [ $toolame -eq 0 -a $mp3 -eq 0 ]; then
         # mp2enc/lame can't read audiodump.wav directly from named pipe,
         # we have to read the whole file.
 	echo "wait, encoding to mp2 audio with mp2enc..."
-        mp2enc -b $abr -r $asr -o $NAME.mpa < $AUDIO
+        mp2enc -b $abr -r $asr -o "$NAME.mpa" < $AUDIO
       elif [ $mp3 -ne 0 ]; then
 	echo "wait, encoding to mp3 audio with lame..."
-        lame -b $abr --resample $kasr - $NAME.mpa < $AUDIO
+        lame -b $abr --resample $kasr - "$NAME.mpa" < $AUDIO
       fi
    fi
 
@@ -399,9 +401,9 @@ if [ $burnonly -eq 0 ]; then
    rm -f $AUDIO
 
    # multiplex streams
-   [ -f $NAME.mpv -a -f $NAME.mpa ] || exit 1
-   rm -f ${NAME}*.mpg
-   mplex $mplexnorm $sync $NAME.mpv $NAME.mpa -o ${NAME}%d.mpg
+   [ -f "$NAME.mpv" -a -f "$NAME.mpa" ] || exit 1
+   rm -f "${NAME}*.mpg"
+   mplex $mplexnorm $sync "$NAME.mpv" "$NAME.mpa" -o "${NAME}%d.mpg"
 
    # remove pipe, won't need anymore!
    rm -f $VIDEO
@@ -410,7 +412,7 @@ if [ $burnonly -eq 0 ]; then
    [ $mpgonly -eq 1 ] && exit 0
 
    # create cd images
-   for mpg in ${NAME}*.mpg; do
+   for mpg in "${NAME}*.mpg"; do
       [ -f $mpg ] || exit 1
       cue="`basename $mpg .mpg`.cue"
       bin="`basename $mpg .mpg`.bin"
@@ -425,7 +427,7 @@ fi
 # burn the (s)vcd's
 [ $burn -eq 0 ] && exit 0
 
-for cue in ${NAME}*.cue; do
+for cue in "${NAME}*.cue"; do
    bin="`basename $cue .cue`.bin"
    [ -f $bin -a -f $cue ] || exit 1
 
@@ -433,8 +435,8 @@ for cue in ${NAME}*.cue; do
    read -n 1 i
 
    if [ $blank -eq 1 ]; then
-      cdrdao blank --reload $CDDEV --driver $CDDRV --blank-mode minimal
+      cdrdao blank --reload --blank-mode minimal
    fi
-   cdrdao write $overburn --reload $CDDEV --driver $CDDRV $cue
+   cdrdao write $overburn --reload $cue
 done
 exit 0
