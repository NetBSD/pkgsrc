# $NetBSD: Makefile,v 1.39 2015/02/11 14:04:16 pho Exp $

DISTNAME=	top-3.6.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.groupsys.com/topinfo/
COMMENT=	The ubiquitous system monitoring utility

GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		SET_OWNER=${BINOWN}
CONFIGURE_ENV+=		SET_GROUP=${BINGRP}
CONFIGURE_ENV+=		SET_MODE=${BINMODE}

# ${WRKSRC}/machine/m_macosx.c uses kvm_* interfaces, which have been
# dropped since Darwin 9.
BROKEN_ON_PLATFORM+=	Darwin-9.*-*
BROKEN_ON_PLATFORM+=	Darwin-[1-9][0-9]*-*

.include "../../mk/bsd.prefs.mk"

.if empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
# ${WRKSRC}/configure emits an error saying "macosx module
# unsupported" without this option.
CONFIGURE_ARGS+=	--with-module=macosx
.endif

post-extract:
	${CP} ${FILESDIR}/m_dragonfly.c ${WRKSRC}/machine

.include "../../mk/bsd.pkg.mk"
