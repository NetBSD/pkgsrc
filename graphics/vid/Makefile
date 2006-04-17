# $NetBSD: Makefile,v 1.17 2006/04/17 13:46:36 wiz Exp $
#

DISTNAME=	vid-1.0.1
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://members.home.com/housel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.home.com/housel/projects.htm
COMMENT=	Simple-minded image capture program for some USB webcams

BUILD_TARGET=	vid


DOCDIR=		share/doc/${PKGBASE}
PLIST_SUBST+=	DOCDIR=${DOCDIR:Q}

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/vid ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
