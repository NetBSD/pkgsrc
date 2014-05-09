# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:03 wiz Exp $

DISTNAME=	talloc-2.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.samba.org/ftp/talloc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://talloc.samba.org/
COMMENT=	Hierarchical pool based memory allocator with destructors
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	talloc.pc.in
PKGCONFIG_OVERRIDE+=	pytalloc-util.pc.in
PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=  33 34 # not yet ported as of 2.1.0

# include/talloc.h
CONFLICTS+=	samba-[0-9]*

REPLACE_PYTHON+=	buildtools/bin/waf
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/ParallelDebug.py
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/batched_cc.py
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/boost.py
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/gccdeps.py
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/go.py
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/lru_cache.py
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/paranoid.py
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/swig.py
REPLACE_PYTHON+=	buildtools/wafadmin/3rdparty/valadoc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Build.py
REPLACE_PYTHON+=	buildtools/wafadmin/Configure.py
REPLACE_PYTHON+=	buildtools/wafadmin/Constants.py
REPLACE_PYTHON+=	buildtools/wafadmin/Environment.py
REPLACE_PYTHON+=	buildtools/wafadmin/Logs.py
REPLACE_PYTHON+=	buildtools/wafadmin/Node.py
REPLACE_PYTHON+=	buildtools/wafadmin/Options.py
REPLACE_PYTHON+=	buildtools/wafadmin/Runner.py
REPLACE_PYTHON+=	buildtools/wafadmin/Scripting.py
REPLACE_PYTHON+=	buildtools/wafadmin/Task.py
REPLACE_PYTHON+=	buildtools/wafadmin/TaskGen.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/__init__.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/ar.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/bison.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/cc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/ccroot.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/compiler_cc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/compiler_cxx.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/compiler_d.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/config_c.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/cs.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/cxx.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/d.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/dbus.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/dmd.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/flex.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/gas.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/gcc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/gdc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/glib2.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/gnome.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/gnu_dirs.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/gob2.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/gxx.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/icc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/icpc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/intltool.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/javaw.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/kde4.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/libtool.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/lua.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/misc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/msvc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/nasm.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/ocaml.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/osx.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/perl.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/preproc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/python.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/qt4.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/ruby.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/suncc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/suncxx.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/tex.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/unittestw.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/vala.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/winres.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/xlc.py
REPLACE_PYTHON+=	buildtools/wafadmin/Tools/xlcxx.py
REPLACE_PYTHON+=	buildtools/wafadmin/Utils.py
REPLACE_PYTHON+=	buildtools/wafadmin/__init__.py
REPLACE_PYTHON+=	buildtools/wafadmin/py3kfixes.py
REPLACE_PYTHON+=	buildtools/wafsamba/samba_python.py
REPLACE_PYTHON+=	buildtools/wafsamba/symbols.py
REPLACE_PYTHON+=	buildtools/wafsamba/wscript
REPLACE_PYTHON+=	lib/replace/system/wscript_configure
REPLACE_PYTHON+=	lib/replace/wscript
REPLACE_PYTHON+=	wscript

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
