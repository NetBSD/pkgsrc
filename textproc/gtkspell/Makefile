# $NetBSD: Makefile,v 1.82 2023/11/14 14:02:58 wiz Exp $

DISTNAME=	gtkspell-2.0.16
PKGREVISION=	40
CATEGORIES=	textproc devel
MASTER_SITES=	http://gtkspell.sourceforge.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtkspell.sourceforge.net/
COMMENT=	Spell checking GtkTextView widget (v2)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	gtkspell-2.0.pc.in
CONFIGURE_ARGS+=	--disable-gtk-doc

.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
