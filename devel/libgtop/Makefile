# $NetBSD: Makefile,v 1.6 1998/12/23 00:18:57 tron Exp $
#

DISTNAME=	libgtop-0.26.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/ \
		ftp://ftp.geo.net/pub/gnome/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-libs-0.30.1:../../x11/gnome-libs
DEPENDS+=	guile-1.2:../../lang/guile
DEPENDS+=	gettext-0.10.35:../../misc/gettext

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-glib-prefix=${LOCALBASE} \
			--with-libgtop-guile --with-catgets
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

post-extract:
	@${MV} ${WRKSRC}/sysdeps/freebsd ${WRKSRC}/sysdeps/bsd

.include "../../mk/bsd.pkg.mk"
