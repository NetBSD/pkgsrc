# $NetBSD: Makefile,v 1.1.1.1 2003/03/23 10:10:25 jmmv Exp $
#

.include "../lyx-qt/Makefile.common"

PKGNAME=	${DISTNAME:S/lyx-/lyx-xforms-/}
COMMENT+=	(xforms version)

CONFLICTS+=	lyx-qt-[0-9]*

CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.xforms} \
			--with-frontend=xforms

.include "../../x11/xforms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
