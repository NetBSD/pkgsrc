# $NetBSD: Makefile,v 1.5 2002/09/14 07:58:03 rh Exp $
#

DISTNAME=		GConf-1.2.1
PKGNAME=		${DISTNAME:S/GConf/GConf2/}
PKGREVISION=		2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/GConf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://advogato.org/proj/GConf/
COMMENT=		configuration database system used by GNOME (v2)

BUILD_USES_MSGFMT=	yes

USE_GNU_GETTEXT=	yes
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
USE_PERL5=		build

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/ptl2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../net/linc/buildlink2.mk"
.include "../../textproc/gtk-doc/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
