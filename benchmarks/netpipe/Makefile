# $NetBSD: Makefile,v 1.9 2007/01/07 09:13:48 rillig Exp $

DISTNAME=	NetPIPE_2.4
PKGNAME=	netpipe-2.4
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.scl.ameslab.gov/netpipe/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scl.ameslab.gov/netpipe/
COMMENT=	TCP/PVM/MPI testing and performance measuring tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews
WRKSRC=		${WRKDIR}/netpipe-2.4

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DHAVE_GETRUSAGE

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	EXTRA_LIBS="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} NPtcp ${PREFIX}/bin/NPtcp ; \
	${INSTALL_MAN} netpipe.1 ${PREFIX}/${PKGMANDIR}/man1/netpipe.1

.include "../../mk/bsd.pkg.mk"
