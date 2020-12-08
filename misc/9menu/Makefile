# $NetBSD: Makefile,v 1.25 2020/12/08 11:15:57 nia Exp $

DISTNAME=		9menu-1.10
CATEGORIES=		misc plan9
MASTER_SITES=		${MASTER_SITE_GITHUB:=arnoldrobbins/}
GITHUB_TAG=		${PKGBASE}-release-${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/arnoldrobbins/9menu
COMMENT=		Simple menu patterned after the Plan9 user interface
LICENSE=		9menu-license

MAKE_FILE=		Makefile.noimake
BUILD_TARGET=		9menu

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9menu ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
