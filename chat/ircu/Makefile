# $NetBSD: Makefile,v 1.11 2004/09/28 12:32:17 adrianp Exp $
#

DISTNAME=	ircu2.10.11.07
PKGNAME=	ircu-2.10.11.07
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=undernet-ircu/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://coder-com.undernet.org/
COMMENT=	Internet Relay Chat server customized for Undernet

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--with-cpath=${PKG_SYSCONFDIR}/ircd.conf
CONFIGURE_ARGS+=	--with-dpath=${DATADIR}
CONFIGURE_ARGS+=	--with-lpath=${DATADIR}/ircd.log
CONFIGURE_ARGS+=	--with-mode=555
CONFIGURE_ARGS+=	--with-owner=0
CONFIGURE_ARGS+=	--with-group=0
CONFIGURE_ARGS+=	--with-symlink=no

PKG_SYSCONFSUBDIR=	ircd

IRCD_USER?=		ircd
IRCD_GROUP?=		ircd
DATADIR=		/var/ircd
OWN_DIRS_PERMS=		${DATADIR} ${IRCD_USER} ${IRCD_GROUP} 0700
EGDIR=			${PREFIX}/share/examples/ircd
DOCDIR=			${PREFIX}/share/doc/ircd

CONF_FILES_PERMS+=	${EGDIR}/ircd.conf.sample ${PKG_SYSCONFDIR}/ircd.conf \
			${IRCD_USER} ${IRCD_GROUP} 0600

SPECIAL_PERMS+=		${PKG_SYSCONFDIR} ${IRCD_USER} ${IRCD_GROUP} 0700

RCD_SCRIPTS=		ircd

FILES_SUBST+=		IRCD_USER=${IRCD_USER}
MESSAGE_SUBST+=		IRCD_USER=${IRCD_USER}
MESSAGE_SUBST+=		IRCD_GROUP=${IRCD_GROUP}
PKG_GROUPS=		${IRCD_GROUP}
PKG_USERS=		${IRCD_USER}:${IRCD_GROUP}::IRC\\ server\\ user:/nonexistant:${SH}

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	tools/README doc/ircd.conf.sample
SUBST_SED.paths=	-e "s|/usr/local/lib/irc|${PKG_SYSCONFDIR}|g" \
			-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."

post-build:
	@cd ${WRKSRC}/tools && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		-f Makefile.crypt

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/ircd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/chkconf \
		${PREFIX}/sbin/ircd-chkconf
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkpasswd \
		${PREFIX}/sbin/ircd-mkpasswd
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/doc/ircd.conf.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/tools/README ${DOCDIR}/README.mkpasswd
	cd ${WRKSRC}/doc && ${INSTALL_DATA} readme.* iauth.txt ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
