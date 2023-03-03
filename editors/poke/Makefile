# $NetBSD: Makefile,v 1.3 2023/03/03 10:31:16 fcambus Exp $

DISTNAME=	poke-3.0
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://ftp.gnu.org/gnu/poke/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://ftp.gnu.org/gnu/poke/
COMMENT=	Extensible editor for structured binary data
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
INFO_FILES=	yes

USE_TOOLS+=	pkg-config gmake makeinfo install-info

CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--with-gc=${BUILDLINK_PREFIX.boehm-gc}
CONFIGURE_ARGS+=	--enable-mi

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-dispatch-no-threading
.endif

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
