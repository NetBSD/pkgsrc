# $NetBSD: Makefile,v 1.34.12.1 2024/02/11 09:15:17 spz Exp $

DISTNAME=		strace-4.5.15
PKGREVISION=		16
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=strace/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/strace/
COMMENT=		Trace system calls
LICENSE=		modified-bsd

# "not supported" according to joerg@
NOT_FOR_PLATFORM+=	DragonFly-*-*

GNU_CONFIGURE=		yes

REPLACE_PERL=		strace-graph
USE_TOOLS+=		perl:run

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
USE_TOOLS+=		autoconf
pre-configure:
	cd ${WRKSRC} && autoconf
.endif

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	NETBSD_SRCDIR=${BSDSRCDIR:Q}
.if !exists(${BSDSRCDIR:Q}/sys/kern/syscalls.master)
PKG_FAIL_REASON+=	"Please place kernel sources in ${BSDSRCDIR:Q}/sys or set BSDSRCDIR"
.endif
pre-configure:
	${CP} -f ${WRKSRC}/syscalls.pl ${WRKSRC}/netbsd

.endif

.include "../../mk/bsd.pkg.mk"
