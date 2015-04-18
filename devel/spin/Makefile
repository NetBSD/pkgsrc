# $NetBSD: Makefile,v 1.3.20.1 2015/04/18 22:13:47 tron Exp $

DISTNAME=	spin525
PKGNAME=	spin-5.2.5
CATEGORIES=	devel
MASTER_SITES=	http://spinroot.com/spin/Src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://spinroot.com/spin/whatispin.html
COMMENT=	Formal correctness prover
LICENSE=	spin-license

# yacc output used without dependency
MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=		${WRKDIR}/Spin/Src5.2.5
USE_TOOLS+=	yacc
MAKE_FILE=	makefile
BUILD_TARGET=	spin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${DESTDIR}${PREFIX}/bin/spin
	${INSTALL_MAN} ${WRKDIR}/Spin/Man/spin.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/spin.1

.include "../../mk/bsd.pkg.mk"
