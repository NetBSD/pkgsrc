# $NetBSD: Makefile,v 1.4 2020/01/18 21:50:04 jperkin Exp $

DISTNAME=	tmate-2.2.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmate-io/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tmate-io/tmate/
COMMENT=	Terminal multiplexer with instant terminal sharing
LICENSE=	isc

USE_TOOLS=	autoconf automake pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
