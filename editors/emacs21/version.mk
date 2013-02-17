# $NetBSD: version.mk,v 1.3 2013/02/17 00:18:58 dholland Exp $

_EMACS_FLAVOR=	emacs
_EMACS_REQD=	emacs21>=21.4<22
_EMACS_PKGDEP.base=
_EMACS_PKGDEP.leim=	leim>=21.${EMACS_VERSION_MINOR}<22:../../editors/leim21

_EMACS_VERSION_MAJOR=	21
_EMACS_VERSION_MINOR=	4
