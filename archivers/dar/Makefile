# $NetBSD: Makefile,v 1.31 2007/10/23 11:15:25 dsainty Exp $

DISTNAME=	dar-2.3.5
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dar.linux.free.fr/
COMMENT=	Disk archiver

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dar-static
CONFIGURE_ARGS+=	--disable-nodump-flag
CONFIGURE_ARGS+=	--disable-upx
CONFIGURE_ARGS+=	--enable-examples
CONFIGURE_ARGS+=	doxygen=no

# Since these are only examples, avoid the dependencies on Bash and
# Perl.  Unfortunately the interpreter replacements won't work unless
# we USE_TOOLS the two interpreters, so the samples are left as is.
CHECK_INTERPRETER_SKIP+=	share/dar/samples/*
#USE_TOOLS+=		bash:run perl:run
#REPLACE_PERL+=		doc/samples/dar_backup
#REPLACE_BASH+=		doc/samples/*.bash doc/samples/clust*.sh

PKG_OPTIONS_VAR=		PKG_OPTIONS.dar
PKG_OPTIONS_OPTIONAL_GROUPS+=	int
PKG_OPTIONS_GROUP.int=		dar-int32 dar-int64
PKG_SUGGESTED_OPTIONS+=		dar-int64

.include "../../mk/bsd.options.mk"

# Dar is built by default with an arbitrary-size-integer library for
# managing all file length/timestamp details.  If 32-bit or 64-bit
# integers (with overflow protection) are sufficient for requirements,
# the following options can significantly reduce the run-time memory
# and CPU overheads of Dar.
.if !empty(PKG_OPTIONS:Mdar-int64)
CONFIGURE_ARGS+=	--enable-mode=64
PLIST_SUBST+=		DARBITS=64
.elif !empty(PKG_OPTIONS:Mdar-int32)
CONFIGURE_ARGS+=	--enable-mode=32
PLIST_SUBST+=		DARBITS=32
.else
PLIST_SUBST+=		DARBITS=
.endif

PKGCONFIG_OVERRIDE=	src/libdar/libdar.pc.tmpl.in
UNLIMIT_RESOURCES=	datasize

# Needed for getopt() with SunPro
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
