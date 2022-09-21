# $NetBSD: Makefile,v 1.35 2022/09/21 13:49:39 ast Exp $

DISTNAME=	radare2-5.7.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=radareorg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.radare.org/
COMMENT=	Reverse engineering framework
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-sysmagic
CONFIGURE_ARGS+=	--with-syscapstone
CONFIGURE_ARGS+=	--with-syszip
PKGCONFIG_OVERRIDE+=	pkgcfg/*.pc*
USE_TOOLS+=		gmake patch pkg-config perl

# node
CHECK_INTERPRETER_SKIP+=	share/radare2/${PKGVERSION_NOREV}/www/m/fonts/iconjar-map.js

#R2VERSION=	${PKGVERSION_NOREV}-git # trunk revision
R2VERSION=	${PKGVERSION_NOREV} # release version
R2VERSION_MN=	${R2VERSION:C/([0-9]*\.[0-9]*).*/\1/}

PLIST_SUBST+=	R2VERSION=${R2VERSION}
PLIST_SUBST+=	R2VERSION_MN=${R2VERSION_MN}

PRINT_PLIST_AWK+=	{ gsub(/${R2VERSION}/, "$${R2VERSION}") }
PRINT_PLIST_AWK+=	{ gsub(/${R2VERSION_MN}/, "$${R2VERSION_MN}") }

.include "options.mk"

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
