# $NetBSD: Makefile,v 1.8 2026/02/09 07:13:13 wiz Exp $

DISTNAME=	spin-6.5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nimble-code/}
GITHUB_PROJECT=	Spin
GITHUB_TAG=	version-${PKGVERSION_NOREV}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://spinroot.com/spin/whatispin.html
COMMENT=	Tool for formal verification of multi-threaded software applications
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Spin-${GITHUB_TAG}
USE_TOOLS+=	pax yacc
MAKE_FILE=	makefile
MAKE_FLAGS=	CC=${CC:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/spin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/spin ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Man/spin.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/spin.1
	cd ${WRKSRC}/Examples && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/examples/spin

.include "../../mk/bsd.pkg.mk"
