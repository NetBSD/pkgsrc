# $NetBSD: Makefile,v 1.13 2023/04/26 19:47:29 wiz Exp $

DISTNAME=		xdelta3-3.1.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=jmacd/}
GITHUB_PROJECT=		xdelta-gpl
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdelta.org/
COMMENT=		Enhanced diff that works on binary files (version 3.x)
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		xdelta3
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin share/doc/xdelta3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${DESTDIR}${PREFIX}/bin/xdelta3
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/xdelta3

do-test:
	${WRKSRC}/xdelta3 test

.include "../../mk/bsd.pkg.mk"
