# $NetBSD: Makefile,v 1.7 2012/09/15 10:05:17 obache Exp $
#

DISTNAME=	tomoe-0.6.0
PKGREVISION=	5
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tomoe.sourceforge.jp/
COMMENT=	Handwriting recognition engine
#LICENSE=	gnu-lgpl-v2.1 # AND Creative Commons Attribution-ShareAlike Licence

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt
USE_PKGLOCALEDIR=	yes

PKG_SYSCONFSUBDIR=	tomoe

PKGCONFIG_OVERRIDE+=	bindings/python/pytomoe.pc.in
PKGCONFIG_OVERRIDE+=	tomoe.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--without-ruby
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ENV+=		ac_cv_path_MYSQL_CONFIG=mysql_config-not-found

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CONF_FILES+=	${PREFIX}/share/examples/tomoe/config ${PKG_SYSCONFDIR}/config

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
