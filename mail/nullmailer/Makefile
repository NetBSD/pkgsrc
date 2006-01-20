# $NetBSD: Makefile,v 1.21 2006/01/20 23:38:47 joerg Exp $

DISTNAME=		nullmailer-1.02
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/nullmailer/
COMMENT=		Simple relay-only mail transport agent

USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+= 	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/spool
CONFIGURE_ARGS+=	--bindir=${PREFIX}/libexec/nullmailer
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/libexec/nullmailer

INSTALL_TARGET=		install install-data-local install-root

.include "../../mk/bsd.prefs.mk"

NULLMAILER_GROUP?=	nullmail
NULLMAILER_USER?=	nullmail
PKG_GROUPS?=		${NULLMAILER_GROUP}
PKG_USERS?=		${NULLMAILER_USER}:${NULLMAILER_GROUP}

MAKE_ENV+=		NULLMAILER_GROUP=${NULLMAILER_GROUP:Q}
MAKE_ENV+=		NULLMAILER_USER=${NULLMAILER_USER:Q}

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}		\
			NULLMAILER_GROUP=${NULLMAILER_GROUP:Q}		\
			NULLMAILER_USER=${NULLMAILER_USER:Q}

FILES_SUBST+=		VARBASE=${VARBASE:Q}				\
			NULLMAILER_GROUP=${NULLMAILER_GROUP:Q}		\
			NULLMAILER_USER=${NULLMAILER_USER:Q}

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
SPECIAL_PERMS+=		${VARBASE}/spool/nullmailer/trigger		\
			${NULLMAILER_USER} ${NULLMAILER_GROUP} 0600
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${PKGDIR}/DEINSTALL

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf
SUBST_FILES.paths+=	doc/nullmailer-send.8 doc/nullmailer-queue.8
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@VARBASE@,${VARBASE},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nullmailer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/nullmailer
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS COPYING ChangeLog	\
		HOWTO NEWS README TODO ${PREFIX}/share/doc/nullmailer
	${INSTALL_DATA} ${WRKDIR}/mailer.conf				\
		${PREFIX}/share/examples/nullmailer/

.include "../../mk/bsd.pkg.mk"
