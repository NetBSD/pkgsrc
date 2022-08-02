# $NetBSD: Makefile,v 1.29 2022/08/02 09:20:43 adam Exp $

DISTNAME=	ldb-2.5.2
CATEGORIES=	databases
MASTER_SITES=	https://www.samba.org/ftp/ldb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ldb.samba.org/
COMMENT=	LDAP-like embedded database
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--abi-check-disable
CONFIGURE_ARGS+=	--disable-symbol-versions
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}
.if defined(MAKE_JOBS) && !empty(MAKE_JOBS) && !(defined(MAKE_JOBS_SAFE) && !empty(MAKE_JOBS_SAFE:M[nN][oO]))
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS}
.else
CONFIGURE_ARGS+=	--jobs=1
.endif
TEST_TARGET=		test

USE_GCC_RUNTIME=	yes

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	buildtools/bin/waf
MAKE_FLAGS+=		WAF_BINARY=${PYTHONBIN}\ ${WRKSRC}/buildtools/bin/waf

.if ${SHLIB_TYPE} == "dylib"
PLIST_SUBST+=	SOEXT=dylib
.else
PLIST_SUBST+=	SOEXT=so
.endif

SUBST_CLASSES+=		docbook
SUBST_MESSAGE.docbook=	Fixing docbook URLs.
SUBST_FILES.docbook+=	buildtools/wafsamba/samba_conftests.py
SUBST_FILES.docbook+=	buildtools/wafsamba/wafsamba.py
SUBST_STAGE.docbook=	pre-configure
SUBST_SED.docbook+=	-e 's,http://docbook.sourceforge.net/release/xsl/current,${PREFIX}/share/xsl/docbook,g'

PLIST_VARS+=	64bit
.if !empty(LP64PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@) || \
	(defined(ABI) && ${ABI} == "64")
PLIST.64bit=		yes
.include "../../databases/lmdb/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ldb-lmdb
.endif

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/talloc/buildlink3.mk"
BUILDLINK_API_DEPENDS.tevent+=	tevent>=0.11.0
.include "../../devel/tevent/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
