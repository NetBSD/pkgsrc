# $NetBSD: Makefile,v 1.13 2003/02/05 22:06:45 jmmv Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2/}
PKGREVISION=	5

CONFIGURE_ENV+=	PKG_USE_GTK=no

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../net/linc/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
