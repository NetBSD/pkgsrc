# $NetBSD: Makefile,v 1.6 2004/12/03 15:15:04 wiz Exp $
#

DISTNAME=	brs.4.00.l1
PKGNAME=	brs-4.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/religion/}

MAINTAINER=	bcv@hub3.net
HOMEPAGE=	http://bible.theverge.com/brs.html
COMMENT=	Interactive King James Version Bible

USE_BUILDLINK3=	YES

WRKSRC=		${WRKDIR}/bible
BUILD_TARGET=	bible

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	bible.1
SUBST_SED.man=		-e s,/usr/local/lib,${PREFIX}/libdata/${PKGBASE},

.include "../../mk/bsd.pkg.mk"
