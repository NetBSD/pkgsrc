# $NetBSD: Makefile,v 1.19 2004/04/25 08:07:21 snj Exp $
#

DISTNAME=	gale-0.99a
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	http://download.gale.org/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://gale.org/
COMMENT=	Secure instant messaging system

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_GNU_READLINE=	# needs rl_named_function()
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/liboopltconfig

GNU_CONFIGURE= 		YES
CONFIGURE_ARGS=		--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		PROG_GLIB_CONFIG="${GLIB_CONFIG}"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.rsaref}/include/rsaref
CPPFLAGS+=		-I${BUILDLINK_PREFIX.libwww}/include/w3c-libwww

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

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../net/adns/buildlink3.mk"
.include "../../security/rsaref/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
