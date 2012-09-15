# $NetBSD: Makefile,v 1.20 2012/09/15 10:05:51 obache Exp $
#

DISTNAME=		${PKGNAME_NOREV}-src
PKGNAME=		openquicktime-1.0
PKGREVISION=		11
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openquicktime/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openquicktime.org/
COMMENT=		Portable library for handling QuickTime(TM) media files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		my_cv_comment=""

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# nbsed creates a config.h that is several megabytes big and contains
# lots of non-printing characters.
USE_TOOLS+=		gsed
.endif

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
