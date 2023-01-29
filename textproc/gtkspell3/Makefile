# $NetBSD: Makefile,v 1.15 2023/01/29 21:15:00 ryoon Exp $

DISTNAME=	gtkspell3-3.0.10
PKGREVISION=	9
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkspell/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtkspell.sourceforge.net/
COMMENT=	Spell checking GtkTextView widget (v3)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	gtkspell-3.0.pc.in
CONFIGURE_ARGS+=	--disable-gtk-doc

.include "../../textproc/enchant2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
