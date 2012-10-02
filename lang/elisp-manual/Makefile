# $NetBSD: Makefile,v 1.18 2012/10/02 20:11:38 asau Exp $

DISTNAME=	elisp-manual-21-2.8
PKGNAME=	elisp-manual-21.2.8
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	The Emacs Lisp Reference Manual for GNU Emacs Version 21.2

CONFLICTS=	{emacs,emacs-nox11}>=22.1 elisp-manual-21-[0-9]*

GNU_CONFIGURE=	YES
INFO_FILES=	YES

BUILD_TARGET=	elisp

INSTALL_MAKE_FLAGS+=	infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}

.include "../../mk/bsd.pkg.mk"
