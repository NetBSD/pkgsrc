# $NetBSD: Makefile,v 1.1.1.1 2000/02/11 10:47:16 agc Exp $
#

DISTNAME=	ddos_scan
PKGNAME=	ddos-scan-20000211
CATEGORIES=	net security x11
MASTER_SITES=	http://staff.washington.edu/dittrich/misc/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://staff.washington.edu/dittrich/

DECOMPRESS_CMD=	${CAT}
ALL_TARGET=	default dds

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=""
.elif ${OPSYS} == "NetBSD"
MAKE_ENV+=	LIBS=""
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dds ${PREFIX}/sbin/dds
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dds

.include "../../mk/bsd.pkg.mk"
