# $NetBSD: Makefile,v 1.11 2026/02/14 08:29:13 wiz Exp $

DISTNAME=	tmate-2.4.0
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmate-io/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tmate-io/tmate
COMMENT=	Terminal multiplexer with instant terminal sharing
LICENSE=	isc

USE_TOOLS=	autoconf automake pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

# for libssh and forkpty detection
LDFLAGS.NetBSD+=	-pthread

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
