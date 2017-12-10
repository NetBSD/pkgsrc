# $NetBSD: Makefile,v 1.6 2017/12/10 14:02:33 adam Exp $

DISTNAME=	spin647
PKGNAME=	spin-6.4.7
CATEGORIES=	devel
MASTER_SITES=	http://spinroot.com/spin/Src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://spinroot.com/spin/whatispin.html
COMMENT=	Formal correctness prover
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/Spin/Src${PKGVERSION_NOREV}
USE_TOOLS+=	yacc
MAKE_FILE=	makefile
MAKE_FLAGS=	CC=${CC:Q}
BUILD_TARGET=	spin

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${DESTDIR}${PREFIX}/bin/spin
	${INSTALL_MAN} ${WRKDIR}/Spin/Man/spin.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/spin.1

.include "../../mk/bsd.pkg.mk"
