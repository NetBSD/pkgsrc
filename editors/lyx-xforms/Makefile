# $NetBSD: Makefile,v 1.26 2009/02/09 22:56:23 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../editors/lyx-qt/Makefile.common"

PKGNAME=	${DISTNAME:S/lyx-/lyx-xforms-/}
PKGREVISION=	1

COMMENT+=	(xforms version)

CONFLICTS+=	lyx-qt-[0-9]*

CONFIGURE_ARGS+=	--with-extra-prefix=${BUILDLINK_PREFIX.xforms} \
			--with-frontend=xforms

.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
