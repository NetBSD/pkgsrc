# $NetBSD: Makefile,v 1.26 2013/02/16 11:22:34 wiz Exp $
#

DISTNAME=	vid-1.0.1
PKGREVISION=	13
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
	${INSTALL_PROGRAM} ${WRKSRC}/vid ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
