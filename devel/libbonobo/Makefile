# $NetBSD: Makefile,v 1.50 2006/09/15 15:06:56 jmmv Exp $

DISTNAME=		libbonobo-2.16.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libbonobo/2.16/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		GNOME2 Object activation framework library

CONFLICTS=		bonobo-activation-[0-9]*

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		bison gmake intltool msgfmt perl:run pkg-config

PKGCONFIG_OVERRIDE=	bonobo/libbonobo-2.0.pc.in
PKGCONFIG_OVERRIDE+=	bonobo-activation/bonobo-activation-2.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		PERL_PATH=${TOOLS_PERL5:Q}

PKG_SYSCONFSUBDIR=	bonobo-activation
EGDIR=			${PREFIX}/share/examples/bonobo-activation
CONF_FILES=		${EGDIR}/bonobo-activation-config.xml \
			${PKG_SYSCONFDIR}/bonobo-activation-config.xml

PRINT_PLIST_AWK+=	/^@dirrm lib\/(bonobo|bonobo\/monikers)$$/ \
				{ print "@unexec $${RMDIR} %D/" $$2 \
				  " 2>/dev/null || $${TRUE}"; next; }

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
