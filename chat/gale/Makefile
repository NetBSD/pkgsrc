# $NetBSD: Makefile,v 1.10 2001/12/02 06:56:39 jlam Exp $
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
CONFIGURE_ARGS=		--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		PROG_GLIB_CONFIG="${GLIB_CONFIG}"

CPPFLAGS+=		-I${BUILDLINK_DIR}/include/rsaref
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/w3c-libwww

PKG_SYSCONFSUBDIR?=	gale
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

PKG_GROUPS=		gale
PKG_USERS=		gale:gale

SUPPORT_FILES=		${EGDIR}/COPYING ${PKG_SYSCONFDIR}/gale/COPYING
SUPPORT_FILES+=		${EGDIR}/ROOT ${PKG_SYSCONFDIR}/gale/auth/trusted/ROOT
OWN_DIRS=		${PKG_SYSCONFDIR}
OWN_DIRS+=		${PKG_SYSCONFDIR}/auth
OWN_DIRS+=		${PKG_SYSCONFDIR}/auth/private
OWN_DIRS+=		${PKG_SYSCONFDIR}/auth/trusted
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/auth/cache			\
			${SHAREOWN} ${SHAREGRP} 0777
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/auth/local			\
			${SHAREOWN} ${SHAREGRP} 1777

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/kutils/ROOT ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${EGDIR}

.include "../../devel/boehm-gc/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../net/adns/buildlink.mk"
.include "../../security/rsaref/buildlink.mk"
.include "../../www/libwww/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
