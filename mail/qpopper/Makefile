# $NetBSD: Makefile,v 1.67 2014/02/12 23:18:09 tron Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		qpopper-${VERSION}
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		${QPOPPER_MASTER_SITES}

PATCH_SITES=		${QPOPPER_PATCHSITES}
PATCHFILES=		${QPOPPER_PATCHFILES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		${QPOPPER_HOMEPAGE}
COMMENT=		Qualcomm's POP server for Eudora

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-apop=${QPOPPER_APOP_AUTH:Q} \
			--enable-popuid=${QPOPPER_USER} \
			--disable-update-abort --without-gdbm

.include "options.mk"

QPOPPER_USER?=		pop
QPOPPER_GROUP?=		mail
QPOPPER_APOP_AUTH?=	${PKG_SYSCONFDIR}/apop.auth

BUILD_DEFS+=		QPOPPER_APOP_AUTH VARBASE
PKG_GROUPS_VARS+=	QPOPPER_GROUP
PKG_USERS_VARS+=	QPOPPER_USER

.if defined(QPOPPER_SPOOL_DIR)
CONFIGURE_ARGS+=	--enable-spool-dir=${QPOPPER_SPOOL_DIR}
.endif

RCD_SCRIPTS=		qpopper
MESSAGE_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS} \
			RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR}

PKG_USERS=		${QPOPPER_USER}:${QPOPPER_GROUP}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	man/popper.8
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	pre-configure
SUBST_FILES.sysconf=	man/popauth.8
SUBST_SED.sysconf=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-configure
SUBST_FILES.varbase=	popper/main.c
SUBST_VARS.varbase=	VARBASE

SPECIAL_PERMS+=		sbin/qpopauth ${QPOPPER_USER} ${REAL_ROOT_GROUP} 4511

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8 sbin share/doc share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/License.txt				\
		${DESTDIR}${PREFIX}/share/doc/qpopper.License
	${INSTALL_DATA} ${WRKSRC}/samples/qpopper.config		\
		 ${DESTDIR}${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
