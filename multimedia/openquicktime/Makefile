# $NetBSD: Makefile,v 1.3 2004/09/24 16:17:53 jlam Exp $
#

DISTNAME=		${PKGNAME_NOREV}-src
PKGNAME=		openquicktime-1.0
PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openquicktime/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.openquicktime.org/
COMMENT=		Portable library for handling QuickTime(TM) media files

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		my_cv_comment=""

pre-configure:
	${ECHO} '#!${SH}' > ${BUILDLINK_DIR}/bin/glib-config-2.0
	${ECHO} '${PREFIX}/bin/pkg-config glib-2.0 "$$@"'		\
		>> ${BUILDLINK_DIR}/bin/glib-config-2.0
	${CHMOD} +x ${BUILDLINK_DIR}/bin/glib-config-2.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
