# $NetBSD: version.mk,v 1.2 2013/02/16 23:58:36 dholland Exp $

_EMACS_FLAVOR=	emacs
_EMACS_REQD=	emacs20>=20.7<21
_EMACS_PKGDEP.base=
_EMACS_PKGDEP.leim=	leim>=20.${EMACS_VERSION_MINOR}<21:../../editors/leim20

_EMACS_VERSION_MAJOR=	20
_EMACS_VERSION_MINOR=	7
