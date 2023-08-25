# $NetBSD: Makefile,v 1.8 2023/08/25 13:52:03 fcambus Exp $

DISTNAME=	poke-3.3
CATEGORIES=	editors
MASTER_SITES=	https://ftp.gnu.org/gnu/poke/

MAINTAINER=	fcambus@NetBSD.org
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
