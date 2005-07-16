# $NetBSD: Makefile,v 1.11 2005/07/16 01:19:10 jlam Exp $

DISTNAME=	monafont-2.90
PKGNAME=	${DISTNAME:S/font/fonts/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=monafont/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://monafont.sourceforge.net/
COMMENT=	Japanese fonts for "Mona" seen at 2ch.net

USE_X11BASE=	yes
USE_PKGINSTALL=	yes
BUILD_TARGET=	bdf
USE_TOOLS+=	gzip perl sed
MAKE_FLAGS+=	SED_CMD=${SED:Q}
MAKE_FLAGS+=	PERL_CMD=${PERL5:Q}
MAKE_FLAGS+=	GZIP_CMD=${GZIP_CMD:Q}

FILES_SUBST+=	X11FONTSSUBDIR=local

post-extract:
	${MKDIR} ${WRKSRC}/dist

.include "../../mk/bsd.pkg.mk"
