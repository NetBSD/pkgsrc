#!/bin/sh
#
#	$Id: mkpthelpers.sh,v 1.1 2003/04/20 06:58:20 rh Exp $
#
# This script creates a Helpers directory in the current directory.
# It will also create a Script.txt if it doesn't exist yet.
# Both are needed for the PanoTools helpers to work.
#
if mkdir Helpers ; then
	for i in PTAverage PTInterpolate PTMorpher PTOptimizer PTStereo	\
	    PTStitcher PTStripe ; do
		ln -s @@prefix@@/libexec/PanoTools/$i Helpers
	done

	cp -R @@prefix@@/share/PanoTools/Templates Helpers
fi

[ -f Script.txt ] ||							\
cp @@prefix@@/share/doc/PanoTools/Stitcher_Script.txt Script.txt
