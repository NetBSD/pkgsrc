# $NetBSD: Makefile,v 1.23 2003/11/12 01:31:47 salo Exp $
#

DISTNAME=		bonobo-activation-2.1.1
PKGREVISION=		3
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/bonobo-activation/2.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		Object activation framework for GNOME2

BUILD_USES_MSGFMT=	YES

USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_PERL5=		build
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/bonobo-activation-2.0.pc.in
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFBASE}"
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

PKG_SYSCONFSUBDIR=	bonobo-activation
EGDIR=			${PREFIX}/share/examples/bonobo-activation
CONF_FILES=		${EGDIR}/bonobo-activation-config.xml \
			${PKG_SYSCONFDIR}/bonobo-activation-config.xml

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/bonobo/monikers

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
