#!/bin/sh
# $NetBSD: beagle-example.sh,v 1.1 2021/05/26 19:13:39 brook Exp $
#
# example script to run beagle
#
# adapted to pkgsrc from the example script at
# https://faculty.washington.edu/browning/beagle/run.beagle.21Apr21.304.example
#

echo
echo "*** Running test analysis with \"gt=\" argument ***"
echo
beagle gt=@EGDIR@/test.21Apr21.304.vcf.gz out=out.gt

echo
echo "*** Running test analysis with \"ref=\" and \"gt=\" arguments ***"
echo
beagle ref=@EGDIR@/ref.21Apr21.304.vcf.gz gt=@EGDIR@/target.21Apr21.304.vcf.gz out=out.ref

echo
echo "*** Making \"bref3\" file ***"
echo
bref3 @EGDIR@/ref.21Apr21.304.vcf.gz > ref.21Apr21.304.bref3

echo
echo "*** Running test analysis with \"bref3\" file ***"
echo
beagle ref=ref.21Apr21.304.bref3 gt=@EGDIR@/target.21Apr21.304.vcf.gz out=out.bref3
