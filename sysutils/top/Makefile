# $NetBSD: Makefile,v 1.44 2026/02/14 08:31:20 wiz Exp $

DISTNAME=	top-3.6.1
PKGREVISION=	1
CATEGORIES=	sysutils
#MASTER_SITES=	ftp://ftp.groupsys.com/pub/top/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	http://www.groupsys.com/topinfo/
COMMENT=	The ubiquitous system monitoring utility

GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		SET_OWNER=${BINOWN}
CONFIGURE_ENV+=		SET_GROUP=${BINGRP}
CONFIGURE_ENV+=		SET_MODE=${BINMODE}

# ${WRKSRC}/machine/m_macosx.c uses kvm_* interfaces, which have been
# dropped since Darwin 9.
BROKEN_ON_PLATFORM+=	Darwin-9.*-*
BROKEN_ON_PLATFORM+=	Darwin-[1-9][0-9]*-*

# ${WRKSRC}/configure emits an error saying "macosx module
# unsupported" without this option.
CONFIGURE_ARGS.Darwin+=	--with-module=macosx

post-extract:
	${CP} ${FILESDIR}/m_dragonfly.c ${WRKSRC}/machine

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
