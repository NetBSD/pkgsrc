# $NetBSD: Makefile,v 1.21 2006/04/18 23:21:18 reed Exp $
#

.include "../../editors/lyx-qt/Makefile.common"

PKGNAME=	${DISTNAME:S/lyx-/lyx-xforms-/}

COMMENT+=	(xforms version)

CONFLICTS+=	lyx-qt-[0-9]*

CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.xforms} \
			--with-frontend=xforms

.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
