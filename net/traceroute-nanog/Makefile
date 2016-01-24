# $NetBSD: Makefile,v 1.7 2016/01/24 16:14:45 jperkin Exp $

DISTNAME=	traceroute-nanog_6.4.2.orig
PKGNAME=	${DISTNAME:S/.orig//:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	ftp://unix.hensa.ac.uk/sites/archive.ubuntu.com/ubuntu/pool/universe/t/traceroute-nanog/ \
		http://www.ftp.uni-erlangen.de/pub/pc/TheOpenCD/old-images/ubuntu/pool/universe/t/traceroute-nanog/ \
		http://traceroute-nanog.sourcearchive.com/downloads/6.4.2-1/

# for the man page:
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	traceroute-nanog_6.4.2-1.diff.gz

COMMENT=	Traceroute implementation with extend features
MAINTAINER=	schwarz@NetBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
NO_CONFIGURE=	YES
USE_FEATURES+=	snprintf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.if ${OS_VERSION} >= 5.0
.if ${OS_VERSION} != 5.4
CPPFLAGS+=	-DSOLARIS
LIBS+=	-lresolv -lsocket -lnsl
.endif
.if ${MACHINE_ARCH} == "i386"
CPPFLAGS+=	-DBYTESWAP_IP_LEN
.endif
.endif
.elif ${OPSYS} == "Linux"
LIBS+=	-lresolv
CPPFLAGS+=	-DSTRING
.elif ${OPSYS} == "FreeBSD"
CPPFLAGS+=	-DSTRING
.elif ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBIND_8_COMPAT -DRA_SERVICE=\"nicname\"
.if !empty(OS_VERSION:M10.*) # MacOS X 10.6.X aka Snow Leopard
LIBS+=	-lresolv
.endif
.elif !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} traceroute.c -o traceroute-nanog ${LDFLAGS} -lm ${LIBS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/traceroute-nanog ${DESTDIR}${PREFIX}/sbin
		${INSTALL_MAN} ${WRKSRC}/${PKGNAME}/debian/traceroute-nanog.genuine.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/traceroute-nanog.8

.include "../../mk/bsd.pkg.mk"
