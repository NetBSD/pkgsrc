# $NetBSD: version.mk,v 1.1 2008/10/11 09:31:56 uebayasi Exp $

_EMACS_FLAVOR=	emacs
_EMACS_REQD=	emacs>=20.7<21
_EMACS_PKGDEP.base=
_EMACS_PKGDEP.leim=	leim>=20.${EMACS_VERSION_MINOR}<21:../../editors/leim20

_EMACS_VERSION_MAJOR=	20
_EMACS_VERSION_MINOR=	7
