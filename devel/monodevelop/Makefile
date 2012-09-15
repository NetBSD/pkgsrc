# $NetBSD: Makefile,v 1.50 2012/09/15 10:04:17 obache Exp $

DISTNAME=	monodevelop-2.4.2
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/monodevelop/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://monodevelop.com/
COMMENT=	IDE for C\# and other .NET languages

PKG_DESTDIR_SUPPORT=	user-destdir

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
MAKE_OVERRIDE+=	tests/UnitTests/MonoDevelop.Projects/PackagingTests.cs
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/templates/Makefile.noauto.project.template
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/templates/Makefile.solution.template
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/templates/make-dist.targets
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/templates/rules.make
MAKE_OVERRIDE+=	src/addins/MonoDevelop.Autotools/SimpleProjectMakefileHandler.cs

SUBST_CLASSES+=			fix-gmake
SUBST_STAGE.fix-gmake=		post-patch
SUBST_MESSAGE.fix-gmake=	Fixing GNU make references
SUBST_FILES.fix-gmake=		${MAKE_OVERRIDE}
SUBST_SED.fix-gmake=		-e 's,MAKEPROGRAM,${MAKE_PROGRAM},'

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
