# $NetBSD: Makefile,v 1.7 2003/02/17 05:20:20 salo Exp $

DISTNAME=		nullmailer-1.00RC7
PKGNAME=		${DISTNAME:S/0RC7/.0.7/}
CATEGORIES=		mail
MASTER_SITES=		http://untroubled.org/nullmailer/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://untroubled.org/nullmailer/
COMMENT=		Simple relay-only mail transport agent

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+= 	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=/var/spool
CONFIGURE_ARGS+=	--bindir=${PREFIX}/libexec/nullmailer
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/libexec/nullmailer

INSTALL_TARGET=		install install-data-local install-root

.include "../../mk/bsd.prefs.mk"

NULLMAILER_GROUP?=	nullmail
NULLMAILER_USER?=	nullmail
PKG_GROUPS?=		${NULLMAILER_GROUP}
PKG_USERS?=		${NULLMAILER_USER}:${NULLMAILER_GROUP}

MAKE_ENV+=		NULLMAILER_GROUP=${NULLMAILER_GROUP}
MAKE_ENV+=		NULLMAILER_USER=${NULLMAILER_USER}

PLIST_SUBST+=		NULLMAILER_GROUP=${NULLMAILER_GROUP}		\
			NULLMAILER_USER=${NULLMAILER_USER}

RCD_SCRIPTS=			nullmailer
RCD_SCRIPT_SRC.nullmailer=	${FILESDIR}/nullmailer

post-configure:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf	>	\
		${WRKDIR}/mailer.conf
	@${MV} ${WRKSRC}/doc/nullmailer-send.8 ${WRKDIR}/nullmailer-send.8
	@${SED} ${FILES_SUBST_SED} ${WRKDIR}/nullmailer-send.8	>	\
		${WRKSRC}/doc/nullmailer-send.8

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nullmailer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/nullmailer
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS COPYING ChangeLog	\
		HOWTO NEWS README TODO ${PREFIX}/share/doc/nullmailer
	${INSTALL_DATA} ${WRKDIR}/mailer.conf				\
		${PREFIX}/share/examples/nullmailer/

.include "../../mk/bsd.pkg.mk"
