# $NetBSD: Makefile,v 1.10 2004/10/03 00:14:58 tv Exp $
#

DISTNAME=	vid-1.0.1
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://members.home.com/housel/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://members.home.com/housel/projects.htm
COMMENT=	Simple-minded image capture program for some USB webcams

ALL_TARGET=	vid

USE_BUILDLINK3=		YES

DOCDIR=		share/doc/${PKGBASE}
PLIST_SUBST+=	DOCDIR=${DOCDIR}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/vid ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
