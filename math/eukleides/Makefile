# $NetBSD: Makefile,v 1.16 2007/11/17 12:04:13 rillig Exp $

DISTNAME=	eukleides.1.0.1
PKGNAME=	eukleides-1.0.1
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://perso.orange.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.orange.fr/obrecht/
COMMENT=	Euclidean geometry drawing language

DEPENDS+=	pstoedit>=3.31:../../graphics/pstoedit

BUILD_TARGET=	eukleides
USE_TOOLS+=	bash:run bison gmake makeinfo lex
INFO_FILES=	# PLIST

REPLACE_BASH=	euk2edit euk2eps

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			BIN=${PREFIX:Q}/bin/				\
			INFO=${PREFIX:Q}/${PKGINFODIR:Q}/		\
			MAN=${PREFIX:Q}/${PKGMANDIR:Q}/man1/

.include "../../mk/bsd.pkg.mk"
