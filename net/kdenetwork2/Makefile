# $NetBSD: Makefile,v 1.14 2002/12/05 12:24:37 tron Exp $

DISTNAME=	kdenetwork-2.2.2
PKGREVISION=	4
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=	YES
PTHREAD_OPTS+=	require

post-build:
	cd ${BUILDLINK_DIR}/lib; \
	${FIND} ${WRKSRC} -name "lib*.so" | ${XARGS} -n 1 ${LN} -fs

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
