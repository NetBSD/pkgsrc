# $NetBSD: Makefile,v 1.12 2004/12/24 04:32:55 wiz Exp $
#

.include "../lyx-qt/Makefile.common"

PKGNAME=	${DISTNAME:S/lyx-/lyx-xforms-/}
PKGREVISION=	1

COMMENT+=	(xforms version)

CONFLICTS+=	lyx-qt-[0-9]*

CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.xforms} \
			--with-frontend=xforms

.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
