# $NetBSD: Makefile,v 1.44 2009/04/18 03:22:31 rh Exp $

DISTNAME=	gnustep-base-1.18.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep foundation classes

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		objc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}
MAKE_FILE=		GNUmakefile
MAKE_JOBS_SAFE=		no

GNUSTEP_OVERRIDE_INSTALL=	YES

pre-configure:
	sed 's|@PREFIX@|${PREFIX}|g' <${FILESDIR}/openapp >${WRKDIR}/openapp

.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"

PTHREAD_LIBS=		-lpthread

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure base.make.in
SUBST_SED.pthread=	-e 's|@PTHREAD_LIBS@|${PTHREAD_LIBS:M*:Q}|g'

.include "../../devel/gnustep-make/gnustep.mk"

CONFIGURE_ARGS+=	--with-library-flags=${GNUSTEP_LDFLAGS:Q}

INSTALLATION_DIRS+=	share/GNUstep/Bundles
INSTALLATION_DIRS+=	share/GNUstep/Frameworks

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
