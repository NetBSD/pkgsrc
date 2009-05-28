# $NetBSD: Makefile,v 1.22 2009/05/28 21:18:40 zafer Exp $

DISTNAME=	monodevelop-2.0
CATEGORIES=	devel
PKGREVISION=	1
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/monodevelop/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://monodevelop.com/
COMMENT=	IDE for C\# and other .NET languages

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:run pkg-config bash:run msgfmt
EXTRACT_USING=	gtar
MAKE_JOBS_SAFE=	no

USE_DIRS+=	xdg-1.4

REPLACE_BASH+=	mdtool.in
REPLACE_BASH+=	monodevelop.in
REPLACE_BASH+=	src/addins/MonoDevelop.Autotools/templates/configure.template
REPLACE_BASH+=	contrib/extract_makefile_variable.sh
REPLACE_BASH+=	theme-icons/icon-theme-installer

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/mono-addins/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/gtksourceview-sharp2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
