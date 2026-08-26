# $NetBSD: Makefile,v 1.13 2026/08/26 10:08:06 drixter Exp $

DISTNAME=	pdsh-2.36
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=chaos/}
GITHUB_PROJECT=	pdsh
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/chaos/pdsh/
COMMENT=	High-performance, parallel remote shell utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run bash:run gmake autoreconf autoconf automake

REPLACE_PERL+=		scripts/dshbak
REPLACE_BASH+=		tests/test-lib.sh

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--with-ssh
CONFIGURE_ARGS+=	--with-dshgroups=${PKG_SYSCONFBASE}/dsh/group
CONFIGURE_ARGS+=	--with-machines=${PKG_SYSCONFDIR}/machines

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
