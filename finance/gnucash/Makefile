# $NetBSD: Makefile,v 1.227 2016/02/01 13:51:47 wiz Exp $

DISTNAME=		gnucash-2.6.11
PKGREVISION=		1
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal or business finance management program
LICENSE=		gnu-gpl-v3

#DEPENDS+=		guile-slib>=3.2.1:../../devel/guile-slib
DEPENDS+=		p5-Finance-Quote-[0-9]*:../../finance/p5-Finance-Quote
DEPENDS+=		p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=		${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
# /usr/pkg/share/gnucash/python/pycons/console.py imports readline
DEPENDS+=		${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=		dconf-[0-9]*:../../devel/dconf

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool makeinfo msgfmt perl:run pkg-config
GNU_CONFIGURE=		yes
INFO_FILES=		YES

CONFIGURE_ARGS+=	--with-html-engine=webkit
CONFIGURE_ARGS+=	--disable-dbi
CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ARGS+=	--with-xdg-data-dirs=${PREFIX}/share
#CONFIGURE_ARGS+=	GUILE=${PREFIX}/${GUILE20_SUBDIR}/bin/guile

REPLACE_PERL+=		src/quotes/gnc-fq-dump
REPLACE_PERL+=		src/backend/xml/test/grab-types.pl
REPLACE_PERL+=		src/quotes/Quote_example.pl
REPLACE_PERL+=		src/gnc-test-env.pl

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 2.6.1
REPLACE_PYTHON+=	src/python/pycons/*.py src/python/pycons/pycons
PY_PATCHPLIST=		yes

PKG_SYSCONFSUBDIR=	gnucash
CONF_FILES+=		${PREFIX}/share/examples/gnucash/gnucash/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${PREFIX}/share/examples/gnucash/gnucash/environment ${PKG_SYSCONFDIR}/environment
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/gnucash

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.28.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../misc/goffice0.8/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-keyring+=	gnome-keyring>=0.6
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
