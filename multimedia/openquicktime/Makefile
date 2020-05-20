# $NetBSD: Makefile,v 1.25 2020/05/20 06:09:07 rillig Exp $
#

DISTNAME=		${PKGNAME_NOREV}-src
PKGNAME=		openquicktime-1.0
PKGREVISION=		13
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

# udta.c: In function 'quicktime_write_udta':
# util.c:213:6: error: array subscript has type 'char' [-Werror=char-subscripts]
#   data[len] = 0;
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

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
