# $NetBSD: unexport-env.mk,v 1.5 2024/09/17 11:52:33 jperkin Exp $

# pick up a bunch of exported vars
FILTER_CMD=	grep ^UT_
.include "export.mk"

# an example of setting up a minimal environment.
PATH=	/bin:/usr/bin:/sbin:/usr/sbin

# now clobber the environment to just PATH and UT_TEST
UT_TEST=	unexport-env

# this removes everything
.unexport-env
.export PATH UT_TEST
