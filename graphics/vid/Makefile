# $NetBSD: Makefile,v 1.19 2009/08/26 19:57:52 sno Exp $
#

DISTNAME=	vid-1.0.1
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://members.home.com/housel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.home.com/housel/projects.htm
COMMENT=	Simple-minded image capture program for some USB webcams

PKG_DESTDIR_SUPPORT=	user-destdir

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
