# $NetBSD: Makefile,v 1.13 2014/10/09 14:05:59 wiz Exp $

DISTNAME=	NetPIPE-3.7.1
PKGNAME=	netpipe-3.7.1
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.scl.ameslab.gov/netpipe/code/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scl.ameslab.gov/netpipe/
COMMENT=	TCP/PVM/MPI testing and performance measuring tool
LICENSE=	gnu-gpl-v2

MAKE_FILE=	makefile
CFLAGS+=	-DHAVE_GETRUSAGE

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	EXTRA_LIBS="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp ${DESTDIR}${PREFIX}/bin/NPtcp
	${INSTALL_MAN} ${WRKSRC}/dox/netpipe.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/netpipe.1

.include "../../mk/bsd.pkg.mk"
