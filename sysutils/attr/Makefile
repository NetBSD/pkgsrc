# $NetBSD: Makefile,v 1.4 2016/08/21 21:09:27 markd Exp $

ATTR_VERS=	2.4.47
PKGNAME=	attr-${ATTR_VERS}
DISTNAME=	attr-${ATTR_VERS}.src
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.gnu.org/releases/attr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/attr
COMMENT=	Commands for Manipulating Filesystem Extended Attributes
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake msgfmt
USE_LIBTOOL=	yes
BUILD_TARGET=	default
INSTALL_SH_OVERRIDE=no

LDFLAGS.Darwin+=	-lintl
LDFLAGS.NetBSD+=	-lintl

SUBST_CLASSES.Darwin+=	rmldarg
SUBST_CLASSES.SunOS+=	rmldarg
SUBST_STAGE.rmldarg=	pre-configure
SUBST_FILES.rmldarg=	libattr/Makefile
SUBST_SED.rmldarg=	-e '/version-script/d'

pre-install:
	cd ${WRKSRC}/libattr && env ${MAKE_ENV} \
            ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
                -f ${MAKE_FILE} install-lib install-dev
	cd ${WRKSRC}/include && env ${MAKE_ENV} \
            ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
                -f ${MAKE_FILE} install-dev

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
