# $NetBSD: Makefile,v 1.1.1.1 2009/05/25 12:50:00 wiz Exp $
#

DISTNAME=	gammu-1.24.0
CATEGORIES=	comms
MASTER_SITES=	http://dl.cihar.com/gammu/releases/ \
		http://mirror.clickcreations.com/gammu/releases/ \
		http://dl.cihar.com.nyud.net/gammu/releases/ \
		ftp://dl.cihar.com/gammu/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cihar.com/gammu/
COMMENT=	Command line utility and library to work with mobile phones
LICENSE=	gnu-gpl-v2

# cmake tests for it; unclear for what it would be used
#BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
# for gammu-config
DEPENDS+=	dialog-[0-9]*:../../misc/dialog

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
CMAKE_ARGS+=	-DINSTALL_MAN_DIR:STRING=${PKGMANDIR}

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run
REPLACE_BASH=	utils/gammu-config utils/jadmaker
PY_PATCHPLIST=	yes

# needed because of https://bugs.cihar.com/view.php?id=908
BUILDLINK_TRANSFORM+=	rm:-Werror

#-- MySQL not found.
#-- Could not find PostgreSQL
#-- libdbi not found.
.include "../../lang/python/extension.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
