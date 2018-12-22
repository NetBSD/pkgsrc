# $NetBSD: Makefile,v 1.29 2018/12/22 08:55:29 adam Exp $

DISTNAME=	talloc-2.1.14
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.samba.org/ftp/talloc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://talloc.samba.org/talloc/doc/html/index.html
COMMENT=	Hierarchical pool based memory allocator with destructors
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=		pkg-config
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	${WRKSRC}/buildtools/bin/waf
CONFIGURE_ARGS+=	configure
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--abi-check-disable
CONFIGURE_ARGS+=	--disable-symbol-versions
.if defined(MAKE_JOBS) && !empty(MAKE_JOBS) && !(defined(MAKE_JOBS_SAFE) && !empty(MAKE_JOBS_SAFE:M[nN][oO]))
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS}
.else
CONFIGURE_ARGS+=	--jobs=1
.endif
TEST_TARGET=		test

PKGCONFIG_OVERRIDE+=	talloc.pc.in
PKGCONFIG_OVERRIDE+=	pytalloc-util.pc.in

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.1.0

# include/talloc.h
CONFLICTS+=	samba<=4.6.8nb3

REPLACE_PYTHON+=	buildtools/bin/waf
REPLACE_PYTHON+=	buildtools/wafsamba/__init__.py
REPLACE_PYTHON+=	buildtools/wafsamba/samba_python.py
REPLACE_PYTHON+=	buildtools/wafsamba/symbols.py
REPLACE_PYTHON+=	buildtools/wafsamba/wscript
REPLACE_PYTHON+=	lib/replace/system/wscript_configure
REPLACE_PYTHON+=	lib/replace/wscript
REPLACE_PYTHON+=	wscript

SUBST_CLASSES+=		docbook
SUBST_MESSAGE.docbook=	Fixing docbook URLs.
SUBST_FILES.docbook+=	buildtools/wafsamba/samba_conftests.py
SUBST_FILES.docbook+=	buildtools/wafsamba/wafsamba.py
SUBST_STAGE.docbook=	pre-configure
SUBST_SED.docbook+=	-e 's,http://docbook.sourceforge.net/release/xsl/current,${PREFIX}/share/xsl/docbook,g'

PY_PATCHPLIST=		yes
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
