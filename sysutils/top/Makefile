# $NetBSD: Makefile,v 1.42 2016/02/26 10:24:14 jperkin Exp $

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

# ${WRKSRC}/configure emits an error saying "macosx module
# unsupported" without this option.
CONFIGURE_ARGS.Darwin+=	--with-module=macosx

post-extract:
	${CP} ${FILESDIR}/m_dragonfly.c ${WRKSRC}/machine

.include "../../mk/bsd.pkg.mk"
