# $NetBSD: Makefile,v 1.10 2023/08/28 13:41:08 fcambus Exp $

DISTNAME=	poke-3.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=poke/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jemarch.net/poke
COMMENT=	Extensible editor for structured binary data
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
INFO_FILES=	yes

USE_TOOLS+=	pkg-config gmake makeinfo install-info

CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--with-gc=${BUILDLINK_PREFIX.boehm-gc}
CONFIGURE_ARGS+=	--enable-mi

# Jitter's no-threading dispatch does not work on NetBSD
CONFIGURE_ARGS.NetBSD+= --disable-dispatch-no-threading

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
