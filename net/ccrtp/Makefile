# $NetBSD: Makefile,v 1.9 2016/03/05 11:27:52 jperkin Exp $
#

DISTNAME=	ccrtp-2.1.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ccrtp/
COMMENT=	RTP and RTSP protocol implementation using GNU CommonCpp
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes
PKGCONFIG_OVERRIDE+=	libccrtp.pc.in
INFO_FILES=		yes

SUBST_CLASSES+=		info
SUBST_FILES.info=	doc/cmake_install.cmake
SUBST_MESSAGE.info=	Fixing infodir path.
SUBST_SED.info=		-e 's|share/info|info|1'
SUBST_STAGE.info=	post-configure

.include "options.mk"

BUILDLINK_API_DEPENDS.ucommon+=	ucommon>=6.3.1
.include "../../devel/ucommon/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
