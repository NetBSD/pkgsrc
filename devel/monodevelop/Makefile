# $NetBSD: Makefile,v 1.98 2018/08/22 09:43:33 wiz Exp $

MD_VERSION=	5.0.1
DISTNAME=	monodevelop-${MD_VERSION}-0
PKGNAME=	monodevelop-${MD_VERSION}
PKGREVISION=	19
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/monodevelop/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://monodevelop.com/
COMMENT=	IDE for C\# and other .NET languages
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/monodevelop-${MD_VERSION}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake:run perl:run pkg-config bash:run msgfmt
EXTRACT_USING=	gtar
MAKE_JOBS_SAFE=	no

REPLACE_BASH+=	mdtool.in
REPLACE_BASH+=	monodevelop.in
REPLACE_BASH+=	src/addins/MonoDevelop.Autotools/templates/configure.template
REPLACE_BASH+=	contrib/extract_makefile_variable.sh
REPLACE_BASH+=	theme-icons/icon-theme-installer

MAKE_OVERRIDE=	src/addins/MonoDeveloperExtensions/MonoSolutionItemHandler.cs
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/SolutionDeployer.cs
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/MakefileProjectServiceExtension.cs
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/templates/Makefile.noauto.project.template
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/templates/Makefile.solution.template
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/templates/make-dist.targets
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/templates/rules.make
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/SimpleProjectMakefileHandler.cs

SUBST_CLASSES+=			fix-gmake
SUBST_STAGE.fix-gmake=		pre-configure
SUBST_MESSAGE.fix-gmake=	Fixing GNU make references
SUBST_FILES.fix-gmake=		${MAKE_OVERRIDE}
SUBST_SED.fix-gmake=		-e 's,MAKEPROGRAM,${MAKE_PROGRAM},'

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	pre-configure
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/mono-addins/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtksourceview-sharp2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
