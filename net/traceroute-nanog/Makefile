# $NetBSD: Makefile,v 1.2 2010/03/20 00:04:21 schwarz Exp $

DISTNAME=	traceroute-nanog-6.4.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.login.com/pub/software/traceroute/
MASTER_SITES+=	http://gd.tuwien.ac.at/infosys/network/tools/traceroute/
DISTFILES=	traceroute.c
DIST_SUBDIR=	traceroute-nanog

# for the man page:
PATCH_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/traceroute-nanog/}
PATCHFILES=	traceroute-nanog_6.3.10-2.diff.gz

PKG_DESTDIR_SUPPORT=	user-destdir

COMMENT=	Traceroute implementation with extend features
MAINTAINER=	schwarz@NetBSD.org

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
USE_FEATURES+=	snprintf

.include "../../mk/bsd.prefs.mk"
.if empty(PKGSRC_COMPILER:Mgcc*)
CPPFLAGS+=	-D__attribute__=
.endif

.if ${OPSYS} == "SunOS"
.if ${OS_VERSION} >= 5.0
.if ${OS_VERSION} != 5.4
CPPFLAGS+=	-DSOLARIS
LIBS+=	-lresolv -lsocket -lnsl
.endif
.if ${LOWER_ARCH} == "i386"
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

do-extract:
		${CP} ${DISTDIR}/${DIST_SUBDIR}/traceroute.c ${WRKSRC}
do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} traceroute.c -o traceroute-nanog ${LDFLAGS} -lm ${LIBS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/traceroute-nanog ${DESTDIR}${PREFIX}/sbin
		${INSTALL_MAN} ${WRKDIR}/traceroute-nanog-6.3.10/debian/traceroute-nanog.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
