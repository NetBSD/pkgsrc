# $NetBSD: Makefile,v 1.12 2004/05/29 11:27:09 shannonjr Exp $
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

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
