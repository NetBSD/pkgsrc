# $NetBSD: Makefile,v 1.16 2003/12/14 19:46:25 jmmv Exp $

DISTNAME=		libbonobo-2.4.2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libbonobo/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		GNOME2 Object activation framework library

CONFLICTS=		bonobo-activation-[0-9]*

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	bonobo/libbonobo-2.0.pc.in
PKGCONFIG_OVERRIDE+=	bonobo-activation/bonobo-activation-2.0.pc.in

CONFIGURE_ARGS= 	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKG_SYSCONFSUBDIR=	bonobo-activation
EGDIR=			${PREFIX}/share/examples/bonobo-activation
CONF_FILES=		${EGDIR}/bonobo-activation-config.xml \
			${PKG_SYSCONFDIR}/bonobo-activation-config.xml

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/bonobo/monikers

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
