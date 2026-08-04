# $NetBSD: Makefile,v 1.17 2026/08/04 20:29:01 wiz Exp $

DISTNAME=	tomoe-0.6.0
PKGREVISION=	9
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/tomoe/
COMMENT=	Handwriting recognition engine
#LICENSE=	gnu-lgpl-v2.1 # AND Creative Commons Attribution-ShareAlike Licence

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
