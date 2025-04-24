# $NetBSD: Makefile,v 1.32 2025/04/24 14:14:41 wiz Exp $
#

DISTNAME=	vid-1.0.1
PKGREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	http://members.home.com/housel/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://members.home.com/housel/projects.htm
COMMENT=	Simple-minded image capture program for some USB webcams

BUILD_TARGET=	vid

DOCDIR=		share/doc/${PKGBASE}
PLIST_SUBST+=	DOCDIR=${DOCDIR}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vid ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
