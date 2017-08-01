# $NetBSD: Makefile,v 1.12 2017/08/01 17:40:14 wiz Exp $
#

DISTNAME=	brs.4.00.l1
PKGNAME=	brs-4.0
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/religion/}

MAINTAINER=	bcv@hub3.net
#HOMEPAGE=	http://bible.theverge.com/brs.html
COMMENT=	Interactive King James Version Bible

WRKSRC=		${WRKDIR}/bible
BUILD_TARGET=	bible

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	bible.1
SUBST_SED.man=		-e s,/usr/local/lib,${PREFIX}/libdata/${PKGBASE},
BUILDLINK_TRANSFORM+=	rm:-fwritable-strings	# gcc4 doesn't know it.

.include "../../mk/bsd.pkg.mk"
