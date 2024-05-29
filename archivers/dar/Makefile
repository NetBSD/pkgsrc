# $NetBSD: Makefile,v 1.68 2024/05/29 16:31:16 adam Exp $

DISTNAME=	dar-2.7.7
PKGREVISION=	6
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dar.linux.free.fr/
COMMENT=	Disk archiver
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake groff gsed pkg-config bash:run

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dar-static
CONFIGURE_ARGS+=	--enable-static=no
CONFIGURE_ARGS+=	--disable-nodump-flag
CONFIGURE_ARGS+=	--disable-upx
CONFIGURE_ARGS+=	--enable-examples
CONFIGURE_ARGS+=	doxygen=no

PKGCONFIG_OVERRIDE=	src/libdar/libdar.pc.tmpl.in

## We use the logic below to find a path for a non-existent ${BASH}.
## Yeah, I suppose it's a hack, but it does work.
#
CHECK_INTERPRETER_SKIP+=	share/dar/samples/*
REPLACE_PERL+=			doc/samples/dar_backup
REPLACE_BASH+=			doc/samples/*.bash doc/samples/*.sh doc/samples/*.duc

EGDIR=			${PREFIX}/share/examples/dar
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CONF_FILES=		${EGDIR}/darrc ${PKG_SYSCONFDIR}/darrc

UNLIMIT_RESOURCES=	datasize

## XXX Needed for getopt() with SunPro (USE_FEATURES?)
#
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/bsd.fast.prefs.mk"

# Building a static binary with threads is currently broken with glibc.
# Building a static binary is not supported on macOS.
.if (${OPSYS} == "Linux" && !empty(PKG_OPTIONS:Mthreads)) || ${OPSYS} == "Darwin"
SUBST_CLASSES+=		static
SUBST_STAGE.static=	pre-configure
SUBST_MESSAGE.static=	Changing -all-static to -static
SUBST_FILES.static=	src/testing/Makefile.in
SUBST_SED.static=	-e 's,-all-static,-static,g'
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
BUILDLINK_TRANSFORM+=	l:execinfo:execinfo:elf
.endif

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
