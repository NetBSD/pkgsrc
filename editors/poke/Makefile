# $NetBSD: Makefile,v 1.11 2026/11/16 01:46:29 ktnb Exp $

DISTNAME=	poke-5.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=poke/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jemarch.net/poke
COMMENT=	Extensible editor for structured binary data
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
INFO_FILES=	yes

USE_TOOLS+=	pkg-config gmake makeinfo install-info
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-gc=${BUILDLINK_PREFIX.boehm-gc}
CONFIGURE_ARGS+=	--enable-mi

# Jitter's no-threading dispatch does not work on NetBSD
CONFIGURE_ARGS.NetBSD+=	--disable-dispatch-no-threading

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
