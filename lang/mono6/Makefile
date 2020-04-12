# $NetBSD: Makefile,v 1.11 2020/04/12 08:27:57 adam Exp $

DISTNAME=	mono-6.8.0.105
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://download.mono-project.com/sources/mono/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/
COMMENT=	Open source implementation of the .NET Development Framework
LICENSE=	mit AND gnu-gpl-v2 AND gnu-lgpl-v2 AND apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}

TOOL_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
CONFLICTS=	pnet-[0-9]* mcsim-[0-9]* lc-[0-9]*
ALL_ENV+=	MONO_SHARED_DIR=${WRKDIR} PLATFORM=
ALL_ENV+=	PAXCTL=${PAXCTL}

USE_TOOLS+=	bash:run cmake gmake gtar msgfmt perl:run pkg-config
USE_TOOLS+=	bison autoconf automake
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c99 c++
EXTRACT_USING=	gtar

GNU_CONFIGURE=		yes
PKG_SYSCONFSUBDIR=	mono
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-btls
CONFIGURE_ARGS+=	--disable-btls-lib

# Requires a cwrappers change: http://mail-index.netbsd.org/tech-pkg/2019/08/16/msg021791.html
USE_CWRAPPERS=		no

MAKE_FLAGS+=		PERL=${PERL5:Q} mandir=${PREFIX}/${PKGMANDIR}
UNLIMIT_RESOURCES=	datasize stacksize memorysize

PKGCONFIG_OVERRIDE+=	mono-uninstalled.pc.in data/cecil.pc.in
PKGCONFIG_OVERRIDE+=	data/dotnet.pc.in data/dotnet35.pc.in data/mint.pc.in
PKGCONFIG_OVERRIDE+=	data/monodoc.pc.in
PKGCONFIG_OVERRIDE+=	data/mono-cairo.pc.in data/mono-lineeditor.pc.in
PKGCONFIG_OVERRIDE+=	data/mono-nunit.pc.in data/mono-options.pc.in
PKGCONFIG_OVERRIDE+=	data/mono.pc.in
PKGCONFIG_OVERRIDE+=	data/reactive.pc.in
PKGCONFIG_OVERRIDE+=	data/system.web.extensions_1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/system.web.extensions.design_1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/system.web.mvc.pc.in data/wcf.pc.in

REPLACE_PERL+=	mono/benchmark/test-driver
REPLACE_PERL+=	mono/cil/make-opcodes-def.pl
REPLACE_PERL+=	mono/tests/stress-runner.pl

REPLACE_PYTHON+=	scripts/mono-heapviz

REPLACE_BASH+=	mono/arch/arm/dpiops.sh
REPLACE_BASH+=	mono/arch/arm/vfpops.sh
REPLACE_BASH+=	scripts/mono-package-runtime
REPLACE_BASH+=	scripts/mono-find-provides.in scripts/mono-find-requires.in
REPLACE_BASH+=	scripts/mono-test-install web/mono-build-w32.sh
REPLACE_BASH+=	mcs/class/Mono.Cairo/Samples/gtk/compile.sh
REPLACE_BASH+=	mcs/class/Mono.Cairo/Samples/png/compile.sh
REPLACE_BASH+=	mcs/class/Mono.Cairo/Samples/win32/compile.sh
REPLACE_BASH+=	mcs/class/Mono.Cairo/Samples/x11/compile.sh
REPLACE_BASH+=	libgc/mkinstalldirs
REPLACE_BASH+=	mcs/mkinstalldirs mkinstalldirs

EGDIR=		${PREFIX}/share/examples/mono

CONF_FILES+=	${EGDIR}/2.0/Browsers/Compat.browser \
		${PKG_SYSCONFDIR}/2.0/Browsers/Compat.browser
CONF_FILES+=	${EGDIR}/2.0/DefaultWsdlHelpGenerator.aspx \
		${PKG_SYSCONFDIR}/2.0/DefaultWsdlHelpGenerator.aspx
CONF_FILES+=	${EGDIR}/2.0/machine.config \
		${PKG_SYSCONFDIR}/2.0/machine.config
CONF_FILES+=	${EGDIR}/2.0/settings.map \
		${PKG_SYSCONFDIR}/2.0/settings.map
CONF_FILES+=	${EGDIR}/2.0/web.config \
		${PKG_SYSCONFDIR}/2.0/web.config
CONF_FILES+=	${EGDIR}/4.0/Browsers/Compat.browser \
		${PKG_SYSCONFDIR}/4.0/Browsers/Compat.browser
CONF_FILES+=	${EGDIR}/4.0/DefaultWsdlHelpGenerator.aspx \
		${PKG_SYSCONFDIR}/4.0/DefaultWsdlHelpGenerator.aspx
CONF_FILES+=	${EGDIR}/4.0/machine.config \
		${PKG_SYSCONFDIR}/4.0/machine.config
CONF_FILES+=	${EGDIR}/4.0/settings.map \
		${PKG_SYSCONFDIR}/4.0/settings.map
CONF_FILES+=	${EGDIR}/4.0/web.config \
		${PKG_SYSCONFDIR}/4.0/web.config
CONF_FILES+=	${EGDIR}/4.5/Browsers/Compat.browser \
		${PKG_SYSCONFDIR}/4.5/Browsers/Compat.browser
CONF_FILES+=	${EGDIR}/4.5/DefaultWsdlHelpGenerator.aspx \
		${PKG_SYSCONFDIR}/4.5/DefaultWsdlHelpGenerator.aspx
CONF_FILES+=	${EGDIR}/4.5/machine.config \
		${PKG_SYSCONFDIR}/4.5/machine.config
CONF_FILES+=	${EGDIR}/4.5/settings.map \
		${PKG_SYSCONFDIR}/4.5/settings.map
CONF_FILES+=	${EGDIR}/4.5/web.config \
		${PKG_SYSCONFDIR}/4.5/web.config
CONF_FILES+=	${EGDIR}/browscap.ini \
		${PKG_SYSCONFDIR}/browscap.ini
CONF_FILES+=	${EGDIR}/config \
		${PKG_SYSCONFDIR}/config

MAKE_DIRS+=	${PKG_SYSCONFDIR}/2.0
MAKE_DIRS+=	${PKG_SYSCONFDIR}/2.0/Browsers
MAKE_DIRS+=	${PKG_SYSCONFDIR}/4.0
MAKE_DIRS+=	${PKG_SYSCONFDIR}/4.0/Browsers
MAKE_DIRS+=	${PKG_SYSCONFDIR}/4.5
MAKE_DIRS+=	${PKG_SYSCONFDIR}/4.5/Browsers
MAKE_DIRS+=	${PKG_SYSCONFDIR}/mconfig

TEST_TARGET=	check

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fixing relative prefix
SUBST_FILES.fix-prefix=		${PKGCONFIG_OVERRIDE}
SUBST_SED.fix-prefix=		-e 's,$${pcfiledir}/../..,\@prefix\@,g'

SUBST_CLASSES+=			fix-cfgdir
SUBST_STAGE.fix-cfgdir=		pre-configure
SUBST_MESSAGE.fix-cfgdir=	Fixing configuration files install dir
SUBST_FILES.fix-cfgdir=		mcs/tools/mconfig/Makefile
SUBST_SED.fix-cfgdir=		-e 's,$$(sysconfdir)/mono,${EGDIR},g'

SUBST_CLASSES+=			fix-libs
SUBST_STAGE.fix-libs=		pre-configure
SUBST_MESSAGE.fix-libs=		Fixing library search path configuration
SUBST_FILES.fix-libs=		configure.ac
SUBST_VARS.fix-libs+=		X11BASE
SUBST_VARS.fix-libs+=		PREFIX

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing python binary name
SUBST_FILES.fix-python+=	mono/mini/Makefile.am.in
SUBST_FILES.fix-python+=	mono/tests/Makefile.am
SUBST_VARS.fix-python=		PYTHONBIN

.include "../../mk/bsd.prefs.mk"

# XXX remove
MAKE_ENV+=	V=1

# We patched makefiles, regen
pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

.if ${OPSYS} == "SunOS"
CFLAGS+=		-D_XOPEN_SOURCE=600
# Conflicts with the above settings
CONFIGURE_ENV+=		ac_cv_func_madvise=no
CONFIGURE_ARGS+=	--with-mcs-docs=no
CONFIGURE_ARGS+=	--enable-dtrace=no
CONFIGURE_ARGS+=	--with-sigaltstack=no
CONFIGURE_ENV+=		ac_cv_func_getdomainname=no
CONFIGURE_ENV+=		ac_cv_func_setdomainname=no
ULIMIT_CMD_datasize=	ulimit -d 524288
ULIMIT_CMD_stacksize=	ulimit -s 10240
.elif ${OPSYS} == "NetBSD"
# Available as a libc symbol, but no declaration.
# XXX learn about getvfsstat
CONFIGURE_ENV+=		ac_cv_func_getfsstat=no
.endif

.if ${MACHINE_ARCH:M*i[34]86*}
# for gcc byte atomic builtins
GNU_ARCH.i386=		i586
CFLAGS+=		-march=i586
.endif

# Unsafe JIT, possibly problematic boehm-gc
NOT_PAX_MPROTECT_SAFE+=	bin/mono-sgen

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/net_4_5/DefaultWsdlHelpGenerator.aspx \
		${DESTDIR}${EGDIR}/4.5/DefaultWsdlHelpGenerator.aspx
	${INSTALL_DATA} ${WRKSRC}/data/net_4_5/machine.config \
		${DESTDIR}${EGDIR}/4.5/machine.config
	${INSTALL_DATA} ${WRKSRC}/data/net_4_5/settings.map \
		${DESTDIR}${EGDIR}/4.5/settings.map
	${INSTALL_DATA} ${WRKSRC}/data/net_4_5/web.config \
		${DESTDIR}${EGDIR}/4.5/web.config
.if ${OPSYS} == "Darwin"
	for lib in mcs.exe.dylib mscorlib.dll.dylib; do \
		install_name_tool -id ${PREFIX}/lib/mono/4.5/$$lib \
		    ${DESTDIR}${PREFIX}/lib/mono/4.5/$$lib; \
	done
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
