# $NetBSD: Makefile,v 1.15 2018/04/17 22:29:32 wiz Exp $

DISTNAME=	radare2-2.3.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=radare/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.radare.org/
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
CHECK_INTERPRETER_SKIP+=	share/radare2/${PKGVERSION_NOREV}/www/m/fonts/iconjar-map.js

.include "options.mk"

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
