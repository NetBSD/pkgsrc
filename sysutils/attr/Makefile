# $NetBSD: Makefile,v 1.1 2014/07/22 08:00:36 manu Exp $

ATTR_VERS=	2.4.47
PKGNAME=	attr-${ATTR_VERS}
DISTNAME=	attr-${ATTR_VERS}.src
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/attr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/attr
COMMENT=	Commands for Manipulating Filesystem Extended Attributes
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake msgfmt
USE_LIBTOOL=	yes
BUILD_TARGET=	default
INSTALL_SH_OVERRIDE=no

pre-install:
	cd ${WRKSRC}/libattr && env ${MAKE_ENV} \
            ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
                -f ${MAKE_FILE} install-lib

.include "../../mk/bsd.prefs.mk"

LDFLAGS.NetBSD+=	-lintl
#MAKE_ENV+=	LTCOMMAND="libtool --install"

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
