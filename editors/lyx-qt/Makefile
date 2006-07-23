# $NetBSD: Makefile,v 1.32 2006/07/23 00:28:12 reed Exp $
#

.include "./Makefile.common"

PKGNAME=	${DISTNAME:S/lyx-/lyx-qt-/}

COMMENT+=	(QT version)

CONFLICTS+=	lyx-xforms-[0-9]*

CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.qt3-libs} \
			--with-qt-dir=${QTDIR:Q} \
			--with-qt-includes=${BUILDLINK_PREFIX.qt3-libs}/qt3/include \
			--with-qt-libraries=${BUILDLINK_PREFIX.qt3-libs}/qt3/lib \
			--with-frontend=qt

# The following is a work-around because $PREFIX/qt3/lib/libqt-mt.so
# didn't link with pthread during the configure check.
CONFIGURE_ENV+=		qt_cv_libname=-lqt-mt

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
