# $NetBSD: Makefile,v 1.8 2002/11/30 23:21:33 salo Exp $
#

DISTNAME=		GConf-1.2.1
PKGNAME=		${DISTNAME:S/GConf/GConf2/}
PKGREVISION=		2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/GConf/1.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://advogato.org/proj/GConf/
COMMENT=		configuration database system used by GNOME (v2)

BUILD_USES_MSGFMT=	yes

USE_GNU_GETTEXT=	yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
USE_PERL5=		build

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../net/linc/buildlink2.mk"
.include "../../textproc/gtk-doc/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
