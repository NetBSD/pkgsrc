# $NetBSD: Makefile,v 1.1.1.1 2003/03/23 09:57:47 jmmv Exp $
#

.include "./Makefile.common"

PKGNAME=	${DISTNAME:S/lyx-/lyx-qt-/}
COMMENT+=	(QT version)

CONFLICTS+=	lyx-xforms-[0-9]*

CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.qt3-libs} \
			--with-qt-dir=${QTDIR} \
			--with-qt-includes=${BUILDLINK_PREFIX.qt3-libs}/qt3/include \
			--with-qt-libraries=${BUILDLINK_PREFIX.qt3-libs}/qt3/lib \
			--with-frontend=qt

.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
