# $NetBSD: Makefile,v 1.34 2025/09/08 07:43:33 vins Exp $
#

DISTNAME=	multitail-7.1.5
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=folkertvanheusden/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.vanheusden.com/multitail/
COMMENT=	View one or multiple files
LICENSE=	mit

USE_CC_FEATURES=	c99

USE_TOOLS+=	perl:run
USE_CURSES=	resize_term wide
FAKE_NCURSES=	yes

REPLACE_PERL+=	conversion-scripts/*.pl

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Adjust conf file for pkgsrc PREFIX
SUBST_FILES.prefix=	multitail.conf
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX

CONF_FILES=	${PREFIX}/share/examples/multitail/multitail.conf	\
		${PKG_SYSCONFDIR}/multitail.conf

CMAKE_CONFIGURE_ARGS+=	-DCONFIG_FILE=${PKG_SYSCONFDIR}/multitail.conf \
			-DCURSES_INCLUDE_PATH=${BUILDLINK_INCDIRS.curses:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-lutil
LDFLAGS+=		-lsocket -lnsl
.elif ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100500
BUILDLINK_TRANSFORM+=	rm:-lutil
.endif

.include "../../devel/cmake/build.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
