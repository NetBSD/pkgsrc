# $NetBSD: Makefile,v 1.65 2025/09/26 15:39:34 schmonz Exp $

DISTNAME=		nullmailer-2.2
PKGREVISION=		17
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE:Q}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/nullmailer/
COMMENT=		Simple relay-only mail transport agent
LICENSE=		gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.if ${INIT_SYSTEM} == "rc.d"
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
.endif

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/libexec/nullmailer
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/libexec/nullmailer

TEST_TARGET=		check
USE_TOOLS+=		bash

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=		${NULLMAILER_GROUP}
PKG_USERS=		${NULLMAILER_USER}:${NULLMAILER_GROUP}
PKG_GROUPS_VARS=	NULLMAILER_GROUP
PKG_USERS_VARS=		NULLMAILER_USER

MAKE_ENV+=		NULLMAILER_GROUP=${NULLMAILER_GROUP}
MAKE_ENV+=		NULLMAILER_USER=${NULLMAILER_USER}

FILES_SUBST+=		VARBASE=${VARBASE}				\
			PKGNAME=${PKGNAME}				\
			NULLMAILER_GROUP=${NULLMAILER_GROUP}		\
			NULLMAILER_USER=${NULLMAILER_USER}

RCD_SCRIPTS=		nullmailer

MAKE_DIRS+=		${PKG_SYSCONFDIR}/nullmailer
.for i in nullmailer nullmailer/queue nullmailer/tmp
OWN_DIRS_PERMS+=	${VARBASE}/spool/${i} ${NULLMAILER_USER}	\
			${NULLMAILER_GROUP} 700
.endfor
SPECIAL_PERMS+=		libexec/nullmailer/mailq			\
			${NULLMAILER_USER} ${NULLMAILER_GROUP} 4555
SPECIAL_PERMS+=		libexec/nullmailer/nullmailer-queue		\
			${NULLMAILER_USER} ${NULLMAILER_GROUP} 4555

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	mailer.conf README.pkgsrc
SUBST_FILES.paths+=	doc/nullmailer-send.8 doc/nullmailer-queue.8
SUBST_FILES.paths+=	test/functions.in
SUBST_VARS.paths=	PREFIX VARBASE PKG_SYSCONFDIR RCD_SCRIPTS_DIR

INSTALLATION_DIRS=	share/doc/${PKGBASE} share/examples/${PKGBASE}
BUILD_DEFS+=		VARBASE

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/mailer.conf ${WRKSRC}/
	${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC}/

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS COPYING ChangeLog	\
		HOWTO NEWS README README.pkgsrc TODO			\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/mailer.conf				\
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
