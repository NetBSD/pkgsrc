# $NetBSD: Makefile,v 1.2 2002/03/13 17:37:18 fredb Exp $
#

DISTNAME=	vid-1.0.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://members.home.com/housel/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://members.home.com/housel/projects.htm
COMMENT=	simple-minded image capture program for some USB webcams

ALL_TARGET=	vid

DOCDIR=		share/doc/${PKGBASE}
PLIST_SUBST+=	DOCDIR=${DOCDIR}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/vid ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}

USE_BUILDLINK_ONLY=	YES

.include "../../graphics/netpbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
