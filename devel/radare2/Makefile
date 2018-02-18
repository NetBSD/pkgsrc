# $NetBSD: Makefile,v 1.11 2018/02/18 17:36:58 kamil Exp $

.include "Makefile.common"

DISTNAME=	radare2-${RADARE2_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=radare/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Reverse engineering framework
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-sysmagic
CONFIGURE_ARGS+=	--with-syscapstone
CONFIGURE_ARGS+=	--with-syszip
PKGCONFIG_OVERRIDE+=	pkgcfg/*.pc*
USE_TOOLS+=	gmake patch pkg-config perl

# node
CHECK_INTERPRETER_SKIP+=	share/radare2/${RADARE2_VERSION}/www/m/fonts/iconjar-map.js

.include "options.mk"

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
