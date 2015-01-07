# $NetBSD: Makefile,v 1.22 2015/01/07 00:15:53 joerg Exp $

DISTNAME=	drac
PKGNAME=	drac-1.12
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/src/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mail.cc.umanitoba.ca/drac/
COMMENT=	Dynamic Relay Authorization Control

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_FLAGS+=	RANLIB=${RANLIB:Q}
MAKE_FLAGS+=	EBIN=${PREFIX}/libexec
MAKE_FLAGS+=	MAN=${PREFIX}/${PKGMANDIR}/man
MAKE_FLAGS+=	MANADM=8
MAKE_FLAGS+=	BDB_LIBS=${BDB_LIBS:Q}

INSTALLATION_DIRS=	include lib libexec ${PKGMANDIR}/man3 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/examples/drac

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
RPCGENFLAGS=	-I -C
.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "OpenBSD"
RPCGENFLAGS=	-C
.elif ${OPSYS} == "SunOS" || ${OPSYS} == "BSDOS" || ${OPSYS} == "AIX"
RPCGENFLAGS=	# empty
.else
RPCGENFLAGS=	# empty
.endif
MAKE_FLAGS+=	RPCGENFLAGS=${RPCGENFLAGS:Q}

CFLAGS.SunOS=	-DTI_RPC -DFCNTL_LOCK -DSYSINFO
CFLAGS.BSDOS=	-DSOCK_RPC -DFCNTL_LOCK -DGETHOST
CFLAGS.IRIX=	-DSOCK_RPC -DFCNTL_LOCK -DGETHOST
CFLAGS.NetBSD=	-DSOCK_RPC -DFCNTL_LOCK -DGETHOST -DDASH_C
CFLAGS.FreeBSD=	-DSOCK_RPC -DFLOCK_LOCK -DGETHOST -DDASH_C
CFLAGS.OpenBSD=	-DSOCK_RPC -DFLOCK_LOCK -DGETHOST -DDASH_C
CFLAGS.Dragonfly=	-DSOCK_RPC -DFLOCK_LOCK -DGETHOST -DDASH_C
CFLAGS.Linux=	-DSOCK_RPC -DFCNTL_LOCK -DGETHOST -DDASH_C
CFLAGS.AIX=	-DD_BSD -DBSD_INCLUDES -DSOCK_RPC -DFCNTL_LOCK -DGETHOST -DDEBUG
LIBS.SunOS=	-lnsl

INSTALL_TARGET=	install install-man

post-install:
.for e in README INSTALL testing.c dracd-setup dracd.allow-sample
	${INSTALL_DATA} ${WRKSRC}/${e} ${DESTDIR}${PREFIX}/share/examples/drac
.endfor
	${INSTALL_DATA} ${WRKSRC}/drac.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libdrac.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
