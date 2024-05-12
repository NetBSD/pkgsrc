# $NetBSD: Makefile,v 1.109 2024/05/12 00:22:02 manu Exp $

DISTNAME=	gnustep-base-1.29.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnustep/}
GITHUB_PROJECT=	libs-base
GITHUB_TAG=	base-1_29_0
WRKSRC=		${WRKDIR}/libs-base-base-1_29_0

PKGREVISION=	4
CATEGORIES=	devel gnustep

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep foundation classes
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		objc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CONFIGURE_ARGS+=	--with-installation-domain=SYSTEM
# Allow building with NetBSD libiconv that does not support //TRANSLIT
CONFIGURE_ARGS+=	--enable-stricticonv
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}
MAKE_FILE=		GNUmakefile

# needs _Unwind_Resume_or_Rethrow from libunwind
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib -lunwind

# ld: -r and -pie may not be used together
MKPIE_SUPPORTED=	no

# GSMime.m:1098:7: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]
# if (isxdigit(*src) && ctxt->pos < sizeof(ctxt->buf))
# Looks suspicious, but ignore for now.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

pre-configure:
	sed 's|@PREFIX@|${PREFIX}|g' <${FILESDIR}/openapp >${WRKDIR}/openapp

.include "../../devel/gnustep-make/gnustep.mk"
.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"

PTHREAD_LIBS=		-lpthread

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_VARS.pthread=	PTHREAD_LIBS
SUBST_MESSAGE.pthread=	Fix @PTHREAD_LIBS@ left out in file configure

CONFIGURE_ARGS+=	--with-library-flags=${GNUSTEP_LDFLAGS:Q}

INSTALLATION_DIRS+=	share/GNUstep/Bundles
INSTALLATION_DIRS+=	share/GNUstep/Frameworks

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
