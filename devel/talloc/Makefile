# $NetBSD: Makefile,v 1.28 2018/07/14 18:51:22 adam Exp $

DISTNAME=	talloc-2.1.14
CATEGORIES=	devel
MASTER_SITES=	http://www.samba.org/ftp/talloc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://talloc.samba.org/talloc/doc/html/index.html
COMMENT=	Hierarchical pool based memory allocator with destructors
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_TOOLS+=		pkg-config
HAS_CONFIGURE=		yes	# wrapper script around WAF
TEST_TARGET=		test

PKGCONFIG_OVERRIDE+=	talloc.pc.in
PKGCONFIG_OVERRIDE+=	pytalloc-util.pc.in
PY_PATCHPLIST=		yes

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

.include "../../mk/bsd.prefs.mk"

# Fix install names of libraries on Darwin.
# Upstream bug report: https://bugzilla.samba.org/show_bug.cgi?id=10791
post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool \
	    -id \
	    ${PREFIX}/lib/libpytalloc-util.${PKGVERSION_NOREV}.dylib \
	    -change \
	    ${WRKSRC}/bin/default/libtalloc.dylib \
	    ${PREFIX}/lib/libtalloc.dylib \
	    ${DESTDIR}${PREFIX}/lib/libpytalloc-util.${PKGVERSION_NOREV}.dylib
	install_name_tool \
	    -id \
	    ${PREFIX}/lib/libtalloc.${PKGVERSION_NOREV}.dylib \
	    ${DESTDIR}${PREFIX}/lib/libtalloc.${PKGVERSION_NOREV}.dylib
	install_name_tool \
	    -change \
	    ${WRKSRC}/bin/default/libpytalloc-util.dylib \
	    ${PREFIX}/lib/libpytalloc-util.dylib \
	    -change \
	    ${WRKSRC}/bin/default/libtalloc.dylib \
	    ${PREFIX}/lib/libtalloc.dylib \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/talloc.so
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
