# $NetBSD: Makefile,v 1.37 2009/05/19 08:59:12 wiz Exp $

DISTNAME=	nano-2.0.8
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v2.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nano-editor.org/
COMMENT=	Small and friendly text editor (a free replacement for Pico)
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

INFO_FILES=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-color
CONFIGURE_ARGS+=	--enable-multibuffer
CONFIGURE_ARGS+=	--enable-nanorc
CONFIGURE_ARGS+=	--enable-extra

# Looks like that IRIX 5.x lacks vsnprintf() functions,
# which are required to make this work, so glib2 is used instead.
.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
.  include "../../devel/glib2/buildlink3.mk"
.endif

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
