# $NetBSD: Makefile,v 1.1.1.1 2003/12/14 03:25:19 xtraeme Exp $
#

.include "${.CURDIR}/../../editors/abiword2/Makefile.common"

PKGNAME=		abiword2-gnome-${DIST_VER}
COMMENT=		Abiword 2.0 (GNOME 2)

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

CONFIGURE_ARGS+=	--enable-gnome

PLIST_SUBST+=		WITH_GNOME=""

CONFLICTS=		abiword2-[0-9]*

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
