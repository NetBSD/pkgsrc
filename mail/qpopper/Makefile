# $NetBSD: Makefile,v 1.61 2008/01/18 05:08:30 tnn Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		qpopper-${VERSION}
PKGREVISION=		1
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
			--enable-popuid=${QPOPPER_USER:Q} \
			--disable-update-abort --without-gdbm

.include "options.mk"

QPOPPER_USER?=		pop
QPOPPER_GROUP?=		mail
QPOPPER_APOP_AUTH?=	${PKG_SYSCONFDIR}/apop.auth

BUILD_DEFS+=		QPOPPER_APOP_AUTH
PKG_GROUPS_VARS+=	QPOPPER_GROUP
PKG_USERS_VARS+=	QPOPPER_USER

.if defined(QPOPPER_SPOOL_DIR)
CONFIGURE_ARGS+=	--enable-spool-dir=${QPOPPER_SPOOL_DIR:Q}
.endif

RCD_SCRIPTS=		qpopper
MESSAGE_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS} \
			RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR}

PKG_USERS?=		${QPOPPER_USER}:${QPOPPER_GROUP}
MAKE_ENV+=		BINGRP=${BINGRP:Q}

SUBST_CLASSES+=		root
SUBST_STAGE.root=	pre-configure
SUBST_FILES.root=	Makefile.in */Makefile.in
SUBST_SED.root=		-e 's,-o root,-o ${ROOT_USER},g'

SUBST_CLASSES+=		libexec
SUBST_STAGE.libexec=	pre-configure
SUBST_FILES.libexec=	man/popper.8
SUBST_SED.libexec=	-e "s|/usr/local/lib|${PREFIX}/libexec|g"

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8 sbin share/doc share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/License.txt				\
		${PREFIX}/share/doc/qpopper.License
	${INSTALL_DATA} ${WRKSRC}/samples/qpopper.config		\
		 ${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
