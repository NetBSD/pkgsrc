# $NetBSD: go-vars.mk,v 1.1 2019/12/09 09:59:31 jperkin Exp $
#
# Makefile fragment to be included by any package that uses go-package.mk.
#
# This needs to be included before bsd.prefs.mk, as the variables set in this
# file are used there to determine whether certain features should be enabled
# or not.
#
# go-package.mk itself can't always be included before bsd.prefs.mk as it
# provides some default targets such as do-install if the package has not
# already defined its own.
#

#
# go uses its own special linker which does not at this time support CTF/SSP.
#
CTF_SUPPORTED=		no
SSP_SUPPORTED=		no
STRIP_DEBUG_SUPPORTED=	no
