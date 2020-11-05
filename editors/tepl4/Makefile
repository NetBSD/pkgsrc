# $NetBSD: Makefile,v 1.3 2020/11/05 09:06:52 ryoon Exp $

DISTNAME=	tepl-4.4.0
PKGNAME=	${DISTNAME:S/tepl-/tepl4-/1}
PKGREVISION=	2
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/tepl/4.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Tepl
COMMENT=	GtkSourceView-based text editors and IDE helper library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

.include "../../devel/amtk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/uchardet/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
