# $NetBSD: Makefile,v 1.7 2001/11/19 21:05:55 jlam Exp $
#

DISTNAME=	gale-0.99a
CATEGORIES=	chat
MASTER_SITES=	http://download.gale.org/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://gale.org
COMMENT=	secure instant messaging system

USE_BUILDLINK_ONLY=	YES
USE_GNU_READLINE=	# needs rl_named_function()
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/liboopltconfig

GNU_CONFIGURE= 		YES
CONFIGURE_ARGS=		--sysconfdir=${CONFDIR}
CONFIGURE_ENV+=		PROG_GLIB_CONFIG="${GLIB_CONFIG}"

CPPFLAGS+=		-I${BUILDLINK_DIR}/include/rsaref
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/w3c-libwww

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

PKG_USER=		gale
PKG_GROUP=		gale

SUPPORT_FILES=		${EGDIR}/COPYING ${CONFDIR}/gale/COPYING
SUPPORT_FILES+=		${EGDIR}/ROOT ${CONFDIR}/gale/auth/trusted/ROOT
OWN_DIRS=		${CONFDIR}/gale
OWN_DIRS+=		${CONFDIR}/gale/auth
OWN_DIRS+=		${CONFDIR}/gale/auth/private
OWN_DIRS+=		${CONFDIR}/gale/auth/trusted
OWN_DIRS_PERMS=		${CONFDIR}/gale/auth/cache ${SHAREOWN} ${SHAREGRP} 0777
OWN_DIRS_PERMS+=	${CONFDIR}/gale/auth/local ${SHAREOWN} ${SHAREGRP} 1777

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/kutils/ROOT ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${EGDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/boehm-gc/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../net/adns/buildlink.mk"
.include "../../security/rsaref/buildlink.mk"
.include "../../www/libwww/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
