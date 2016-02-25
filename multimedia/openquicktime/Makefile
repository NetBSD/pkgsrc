# $NetBSD: Makefile,v 1.23 2016/02/25 15:49:44 jperkin Exp $
#

DISTNAME=		${PKGNAME_NOREV}-src
PKGNAME=		openquicktime-1.0
PKGREVISION=		12
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openquicktime/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openquicktime.org/
COMMENT=		Portable library for handling QuickTime(TM) media files

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		my_cv_comment=""

# nbsed creates a config.h that is several megabytes big and contains
# lots of non-printing characters.
OPSYSVARS+=		USE_TOOLS
USE_TOOLS.SunOS+=	gsed

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin lib

pre-configure:
	${ECHO} '#!${SH}' > ${BUILDLINK_DIR}/bin/glib-config-2.0
	${ECHO} '${PREFIX}/bin/pkg-config glib-2.0 "$$@"'		\
		>> ${BUILDLINK_DIR}/bin/glib-config-2.0
	${CHMOD} +x ${BUILDLINK_DIR}/bin/glib-config-2.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
