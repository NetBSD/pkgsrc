# $NetBSD: Makefile,v 1.26 2005/09/07 13:58:16 adam Exp $

DISTNAME=	gale-0.99fruit
PKGNAME=	gale-0.99f
CATEGORIES=	chat
MASTER_SITES=	http://download.ofb.net/gale/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gale.org/
COMMENT=	Secure instant messaging system

USE_PKGINSTALL=		yes
USE_GNU_READLINE=	yes	# needs rl_named_function()
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/liboopltconfig
GNU_CONFIGURE= 		yes
CONFIGURE_ARGS=		--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		PROG_GLIB_CONFIG="${GLIB_CONFIG}"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.rsaref}/include/rsaref
CPPFLAGS+=		-I${BUILDLINK_PREFIX.libwww}/include/w3c-libwww
CPPFLAGS+=		-I${BUILDLINK_PREFIX.tcl}/include/tcl

PKG_SYSCONFSUBDIR?=	gale
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

PKG_GROUPS=		gale
PKG_USERS=		gale:gale

CONF_FILES=		${EGDIR}/COPYING ${PKG_SYSCONFDIR}/gale/COPYING
CONF_FILES+=		${EGDIR}/ROOT ${PKG_SYSCONFDIR}/gale/auth/trusted/ROOT
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
.include "../../lang/tcl/buildlink3.mk"
.include "../../net/adns/buildlink3.mk"
.include "../../security/rsaref/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
