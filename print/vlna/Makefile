# $NetBSD: Makefile,v 1.3 2016/06/16 04:06:20 markd Exp $

DISTNAME=	texlive-20160523-source
PKGNAME=	vlna-1.5
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2016/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Adds tilde after each non-syllabic preposition

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/utils/vlna

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/utils/vlna

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

.include "../../mk/bsd.pkg.mk"
