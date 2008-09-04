# $NetBSD: Makefile,v 1.67.4.2 2008/09/04 21:37:19 tron Exp $

DISTNAME=	mono-${MONO_VERSION}
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://go-mono.com/sources/mono/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Open source implementation of the .NET Development Framework

BUILD_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

CONFLICTS=	pnet-[0-9]*

MONO_VERSION=		1.9.1
ALL_ENV+=		MONO_SHARED_DIR=${WRKDIR:Q}

USE_TOOLS+=		bison gmake gtar perl:run pkg-config bash:run
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
EXTRACT_USING=		gtar

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-icu=yes
CONFIGURE_ARGS+=	--with-preview=yes
CONFIGURE_ARGS+=	--with-libgdiplus=installed
CONFIGURE_ARGS+=	--with-moonlight=no

MAKE_JOBS_SAFE=		no

MAKE_FLAGS+=		PERL=${PERL5:Q}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
UNLIMIT_RESOURCES=	datasize
UNLIMIT_RESOURCES+=	stacksize
UNLIMIT_RESOURCES+=	memorysize

PKGCONFIG_OVERRIDE+=	mono-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	data/cecil.pc.in
PKGCONFIG_OVERRIDE+=	data/dotnet.pc.in
PKGCONFIG_OVERRIDE+=	data/mint.pc.in
PKGCONFIG_OVERRIDE+=	data/mono-cairo.pc.in
PKGCONFIG_OVERRIDE+=	data/mono.pc.in
PKGCONFIG_OVERRIDE+=	scripts/mono-nunit.pc.in

REPLACE_PERL+=	mcs/errors/do-tests.pl
REPLACE_PERL+=	mcs/tools/scan-tests.pl
REPLACE_PERL+=	msvc/create-windef.pl
REPLACE_PERL+=	mono/benchmark/test-driver
REPLACE_PERL+=	mono/cil/make-opcodes-def.pl
REPLACE_PERL+=	mono/metadata/make-bundle.pl
REPLACE_PERL+=	mono/mini/genmdesc.pl
REPLACE_PERL+=	mono/tests/stress-runner.pl

REPLACE_BASH+=	mono/arch/arm/dpiops.sh
REPLACE_BASH+=	mono/arch/arm/fpaops.sh
REPLACE_BASH+=	mono/arch/arm/vfpops.sh
REPLACE_BASH+=	scripts/mono-find-provides.in
REPLACE_BASH+=	scripts/mono-find-requires.in
REPLACE_BASH+=	scripts/mono-test-install
REPLACE_BASH+=	web/mono-build-w32.sh
REPLACE_BASH+=	mcs/class/Mono.Mozilla/build-csproj2k5
REPLACE_BASH+=	mcs/class/Managed.Windows.Forms/build-csproj
REPLACE_BASH+=	mcs/class/Managed.Windows.Forms/build-csproj2k5
REPLACE_BASH+=	mcs/class/Mono.Cairo/Samples/gtk/compile.sh
REPLACE_BASH+=	mcs/class/Mono.Cairo/Samples/png/compile.sh
REPLACE_BASH+=	mcs/class/Mono.Cairo/Samples/win32/compile.sh
REPLACE_BASH+=	mcs/class/Mono.Cairo/Samples/x11/compile.sh
REPLACE_BASH+=	mcs/tools/tinderbox/tinderbox.sh

EGDIR=		${PREFIX}/share/examples/mono
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/mono/config
CONF_FILES+=	${EGDIR}/browscap.ini ${PKG_SYSCONFDIR}/mono/browscap.ini
CONF_FILES+=	${EGDIR}/1.0/DefaultWsdlHelpGenerator.aspx \
		${PKG_SYSCONFDIR}/mono/1.0/DefaultWsdlHelpGenerator.aspx
CONF_FILES+=	${EGDIR}/1.0/machine.config \
		${PKG_SYSCONFDIR}/mono/1.0/machine.config
CONF_FILES+=	${EGDIR}/2.0/DefaultWsdlHelpGenerator.aspx \
		${PKG_SYSCONFDIR}/mono/2.0/DefaultWsdlHelpGenerator.aspx
CONF_FILES+=	${EGDIR}/2.0/machine.config \
		${PKG_SYSCONFDIR}/mono/2.0/machine.config
CONF_FILES+=	${EGDIR}/mconfig/config.xml \
		${PKG_SYSCONFDIR}/mono/mconfig/config.xml

MAKE_DIRS+=	${PKG_SYSCONFDIR}/mono/1.0
MAKE_DIRS+=	${PKG_SYSCONFDIR}/mono/2.0
MAKE_DIRS+=	${PKG_SYSCONFDIR}/mono/mconfig

TEST_TARGET=	check

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		post-patch
SUBST_MESSAGE.fix-prefix=	Fixing relative prefix
SUBST_FILES.fix-prefix=		${PKGCONFIG_OVERRIDE}
SUBST_SED.fix-prefix=		-e 's,$${pcfiledir}/../..,\@prefix\@,g'

SUBST_CLASSES+=			fix-mcs
SUBST_STAGE.fix-mcs=		post-patch
SUBST_MESSAGE.fix-mcs=		Fixing mcs default prefix
SUBST_FILES.fix-mcs=		mcs/build/config-default.make
SUBST_SED.fix-mcs=		-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=			fix-cfgdir
SUBST_STAGE.fix-cfgdir=		post-patch
SUBST_MESSAGE.fix-cfgdir=	Fixing configuration files install dir
SUBST_FILES.fix-cfgdir=		mcs/tools/mconfig/Makefile
SUBST_SED.fix-cfgdir=		-e 's,$$(sysconfdir)/mono,${EGDIR},g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
