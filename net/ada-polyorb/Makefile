# $NetBSD: Makefile,v 1.2 2026/01/07 18:08:33 dkazankov Exp $

DISTNAME=	polyorb-${PKGVERSION_NOREV}
PKGNAME=	polyorb-${GNAT_NAME}-25.0.0
PKGREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	PolyORB
GITHUB_TAG=	25.0

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/PolyORB
COMMENT=	Polymorphic, reusable infrastructure for building distributed systems
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	awk gmake

USE_LANGUAGES=	c ada

GNU_CONFIGURE=	yes

CHECK_PIE_SKIP+=	${GNAT_PKGBASE}/bin/*

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

.include "options.mk"

GNU_CONFIGURE_PREFIX=	${DESTDIR}${GNAT_PREFIX}

OVERRIDE_RELEASE_PLACEHOLDER=	25.0w
ADDITIONAL_VERSION_PLACEHOLDER=

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Set version in ${SUBST_FILES.version}
SUBST_VARS.version=	OVERRIDE_RELEASE_PLACEHOLDER ADDITIONAL_VERSION_PLACEHOLDER
SUBST_FILES.version=	configure

# Use C preprocessed symbols on NetBSD (only)
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		time
SUBST_MESSAGE.time=	Replace time with __gnat_time in ${SUBST_FILES.time}
SUBST_STAGE.time=	pre-configure
SUBST_FILES.time=	cos/time/time_utils.adb
SUBST_SED.time=		-e "s,\"time\",\"__gnat_time\","
.endif

CONFIGURE_ARGS+=	--with-appli-perso=${APP_PERSONALITIES:Q}
CONFIGURE_ARGS+=	--with-proto-perso=${PROTOCOL_PERSONALITIES:Q}
.if !empty(CORBA_SERVICES)
CONFIGURE_ARGS+=	--with-corba-services=${CORBA_SERVICES:Q}
.endif
EXTRA_GNATMAKE_FLAGS+=	-eL -R -largs $${LDFLAGS} -margs
CONFIGURE_ENV+=		EXTRA_GNATMAKE_FLAGS=${EXTRA_GNATMAKE_FLAGS:Q}

PLIST_VARS+=		shlibs

USE_PKGSRC_GCC_RUNTIME?=		no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=				yes
CONFIGURE_ARGS+=			--enable-shared
CONFIGURE_ARGS+=			--with-gprbuild=gprbuild
BUILDLINK_DEPMETHOD.xmlada-25=		full
BUILDLINK_DEPMETHOD.libgpr-25=		full
BUILDLINK_DEPMETHOD.gnatcoll-core-25=	full
.else
CONFIGURE_ARGS+=			--disable-shared
.endif

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${GNAT_PREFIX}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
