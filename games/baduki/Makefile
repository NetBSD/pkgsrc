# $NetBSD: Makefile,v 1.18 2001/06/11 06:34:32 jlam Exp $

DISTNAME=	baduki-0.2.9
CATEGORIES=	games
MASTER_SITES=	http://soback.kornet21.net/~artist/baduk/

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://soback.kornet21.net/~artist/baduk/baduki.html
COMMENT=	Go playing program based on xamigo

BUILD_USES_MSGFMT=	yes
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_LIBINTL=	yes

EVAL_PREFIX+=	GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix=${GTKDIR}
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=	GTK_CONFIG="${GTKDIR}/bin/gtk-config"
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
