# $NetBSD: Makefile,v 1.1.1.1 2003/04/23 10:06:54 rh Exp $
#

DISTNAME=		${PKGNAME}-src
PKGNAME=		openquicktime-1.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openquicktime/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openquicktime.org/
COMMENT=		portable library for handling QuickTime(TM) media files

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		my_cv_comment=""

pre-configure:
	${ECHO} '#!${SH}' > ${BUILDLINK_DIR}/bin/glib-config-2.0
	${ECHO} '${PREFIX}/bin/pkg-config glib-2.0 "$$@"'		\
		>> ${BUILDLINK_DIR}/bin/glib-config-2.0
	${CHMOD} +x ${BUILDLINK_DIR}/bin/glib-config-2.0

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
