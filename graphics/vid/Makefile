# $NetBSD: Makefile,v 1.4 2002/10/09 14:40:26 wiz Exp $
#

DISTNAME=	vid-1.0.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://members.home.com/housel/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://members.home.com/housel/projects.htm
COMMENT=	simple-minded image capture program for some USB webcams

ALL_TARGET=	vid

USE_BUILDLINK2=		YES

DOCDIR=		share/doc/${PKGBASE}
PLIST_SUBST+=	DOCDIR=${DOCDIR}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/vid ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}

.include "../../graphics/netpbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
