# $NetBSD: Makefile,v 1.5 2003/08/05 13:37:17 drochner Exp $
#

.include "./Makefile.common"

PKGNAME=	${DISTNAME:S/lyx-/lyx-qt-/}
PKGREVISION=	2

COMMENT+=	(QT version)

CONFLICTS+=	lyx-xforms-[0-9]*

CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.qt3-libs} \
			--with-qt-dir=${QTDIR} \
			--with-qt-includes=${BUILDLINK_PREFIX.qt3-libs}/qt3/include \
			--with-qt-libraries=${BUILDLINK_PREFIX.qt3-libs}/qt3/lib \
			--with-frontend=qt

.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
