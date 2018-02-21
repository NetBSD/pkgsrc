# $NetBSD: Makefile,v 1.24 2018/02/21 15:12:00 triaxx Exp $

DISTNAME=		9menu-1.9
CATEGORIES=		misc plan9
GITHUB_TAG=		${PKGBASE}-release-${PKGVERSION_NOREV}
MASTER_SITES=		${MASTER_SITE_GITHUB:=arnoldrobbins/}
LICENSE=		9menu-license

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Simple menu patterned after the plan9 user interface

MAKE_FILE=		Makefile.noimake
BUILD_TARGET=		9menu

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9menu ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
