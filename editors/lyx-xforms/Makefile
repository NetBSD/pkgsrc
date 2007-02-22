# $NetBSD: Makefile,v 1.24 2007/02/22 19:26:25 wiz Exp $
#

.include "../../editors/lyx-qt/Makefile.common"

PKGNAME=	${DISTNAME:S/lyx-/lyx-xforms-/}

COMMENT+=	(xforms version)

CONFLICTS+=	lyx-qt-[0-9]*

CONFIGURE_ARGS+=	--with-extra-prefix=${BUILDLINK_PREFIX.xforms} \
			--with-frontend=xforms

.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
