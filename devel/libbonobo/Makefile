# $NetBSD: Makefile,v 1.26 2004/04/01 18:18:00 jmmv Exp $

DISTNAME=		libbonobo-2.6.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libbonobo/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		GNOME2 Object activation framework library

CONFLICTS=		bonobo-activation-[0-9]*

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make yacc

PKGCONFIG_OVERRIDE=	bonobo/libbonobo-2.0.pc.in
PKGCONFIG_OVERRIDE+=	bonobo-activation/bonobo-activation-2.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKG_SYSCONFSUBDIR=	bonobo-activation
EGDIR=			${PREFIX}/share/examples/bonobo-activation
CONF_FILES=		${EGDIR}/bonobo-activation-config.xml \
			${PKG_SYSCONFDIR}/bonobo-activation-config.xml

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
