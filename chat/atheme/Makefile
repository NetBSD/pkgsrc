# $NetBSD: Makefile,v 1.1.1.1 2008/06/16 10:38:27 adrianp Exp $
#

DISTNAME=	atheme-services-3.0.4
PKGNAME=	${DISTNAME:S/-services//}
CATEGORIES=	chat
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tbz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.atheme.org/
COMMENT=	Flexible IRC services system with proven scalability

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	atheme
EGDIR=			${PREFIX}/share/examples/atheme
DOC_FILES=		INSTALL README
MAKE_JOBS_SAFE=		NO
ATHEME_USER?=		atheme
ATHEME_GROUP?=		atheme

RCD_SCRIPTS+=		atheme

PKG_USERS_VARS=		ATHEME_USER
PKG_GROUPS_VARS=	ATHEME_GROUP
PKG_GROUPS=		${ATHEME_GROUP}
PKG_USERS=		${ATHEME_USER}:${ATHEME_GROUP}

PKG_GECOS.${ATHEME_USER}=	atheme user

FILES_SUBST+=		ATHEME_USER=${ATHEME_USER}
FILES_SUBST+=		ATHEME_GROUP=${ATHEME_GROUP}

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--enable-fhs-paths
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKGCONFIG_OVERRIDE+=	libmowgli/libmowgli.pc.in

CONF_FILES_PERMS=	${EGDIR}/atheme.conf.example \
			${PKG_SYSCONFDIR}/atheme.conf \
			${ATHEME_USER} ${ATHEME_GROUP} 0660
CONF_FILES_PERMS+=	${EGDIR}/atheme.cron.example \
			${PKG_SYSCONFDIR}/atheme.cron \
			${ATHEME_USER} ${ATHEME_GROUP} 0660
CONF_FILES_PERMS+=	${EGDIR}/atheme.motd.example \
			${PKG_SYSCONFDIR}/atheme.motd \
			${ATHEME_USER} ${ATHEME_GROUP} 0660
CONF_FILES_PERMS+=	${EGDIR}/atheme.conf.userserv-example \
			${PKG_SYSCONFDIR}/atheme.conf.userserv \
			${ATHEME_USER} ${ATHEME_GROUP} 0660

MAKE_DIRS_PERMS+=	${VARBASE}/atheme \
			${ATHEME_USER} ${ATHEME_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/log/atheme \
			${ATHEME_USER} ${ATHEME_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/run/atheme \
			${ATHEME_USER} ${ATHEME_GROUP} 0770

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/atheme.conf.example \
		${EGDIR}/atheme.conf.example
	${INSTALL_DATA} ${WRKSRC}/dist/atheme.conf.userserv-example \
		${EGDIR}/atheme.conf.userserv-example
	${INSTALL_DATA} ${WRKSRC}/dist/atheme.cron.example \
		${EGDIR}/atheme.cron.example
	${INSTALL_DATA} ${WRKSRC}/dist/atheme.motd.example \
		${EGDIR}/atheme.motd.example
.	for i in ${DOC_FILES}
		${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/atheme/
.	endfor

.include "../../devel/mowgli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
