# $NetBSD: Makefile,v 1.14 2024/08/21 19:23:53 wiz Exp $

DISTNAME=	traceroute-nanog_6.4.2.orig
PKGNAME=	${DISTNAME:S/.orig//:S/_/-/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://archive.debian.org/debian//pool/main/t/traceroute-nanog/

# for the man page:
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	traceroute-nanog_6.4.2-1.diff.gz

COMMENT=	Traceroute implementation with extended features
MAINTAINER=	schwarz@NetBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
NO_CONFIGURE=	YES
USE_FEATURES+=	snprintf

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CPPFLAGS+=	-DBYTESWAP_IP_LEN
.endif

CPPFLAGS.FreeBSD+=	-DSTRING
CPPFLAGS.Linux+=	-DSTRING
CPPFLAGS.SunOS+=	-DSOLARIS

LIBS.Linux+=		-lresolv
LIBS.SunOS+=		-lresolv -lsocket -lnsl

.if ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBIND_8_COMPAT -DRA_SERVICE=\"nicname\"
.  if !empty(OS_VERSION:M1[0-9].*) # MacOS X 10.6.X aka Snow Leopard, or later
LIBS+=		-lresolv
.  endif
.endif

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

SPECIAL_PERMS+=		sbin/traceroute-nanog ${SETUID_ROOT_PERMS}

do-build:
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} traceroute.c -o traceroute-nanog ${LDFLAGS} -lm ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/traceroute-nanog ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/traceroute-nanog-${PKGVERSION_NOREV}/debian/traceroute-nanog.genuine.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/traceroute-nanog.8

.include "../../mk/bsd.pkg.mk"
