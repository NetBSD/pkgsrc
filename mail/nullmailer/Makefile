# $NetBSD: Makefile,v 1.40 2016/12/12 23:54:12 wiedi Exp $

DISTNAME=		nullmailer-1.13
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE:Q}
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/nullmailer/
COMMENT=		Simple relay-only mail transport agent

LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/spool
CONFIGURE_ARGS+=	--bindir=${PREFIX}/libexec/nullmailer
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/libexec/nullmailer

.include "../../mk/bsd.prefs.mk"

NULLMAILER_GROUP?=	nullmail
NULLMAILER_USER?=	nullmail
PKG_GROUPS=		${NULLMAILER_GROUP}
PKG_USERS=		${NULLMAILER_USER}:${NULLMAILER_GROUP}
PKG_GROUPS_VARS=	NULLMAILER_GROUP
PKG_USERS_VARS=		NULLMAILER_USER

MAKE_ENV+=		NULLMAILER_GROUP=${NULLMAILER_GROUP}
MAKE_ENV+=		NULLMAILER_USER=${NULLMAILER_USER}

FILES_SUBST+=		VARBASE=${VARBASE}				\
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
SUBST_FILES.paths=	${WRKDIR}/mailer.conf ${WRKDIR}/nullmailer-daemon
SUBST_FILES.paths+=	doc/nullmailer-send.8 doc/nullmailer-queue.8
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@VARBASE@,${VARBASE},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-configure

INSTALLATION_DIRS=	share/doc/${PKGBASE} share/examples/${PKGBASE}
BUILD_DEFS+=		VARBASE

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf
	${CP} ${FILESDIR}/nullmailer-daemon ${WRKDIR}/nullmailer-daemon

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS COPYING ChangeLog	\
		HOWTO NEWS README TODO ${DESTDIR}${PREFIX}/share/doc/nullmailer
	${INSTALL_DATA} ${WRKDIR}/mailer.conf				\
		${DESTDIR}${PREFIX}/share/examples/nullmailer/
	${INSTALL_SCRIPT} ${WRKDIR}/nullmailer-daemon			\
		${DESTDIR}${PREFIX}/libexec/nullmailer/

.include "../../mk/bsd.pkg.mk"
