# $NetBSD: Makefile,v 1.32 2005/01/23 10:00:12 jdolecek Exp $

DISTNAME=		dovecot-0.99.13
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/releases/

MAINTAINER=		tom@replic8.net
HOMEPAGE=		http://www.dovecot.org/
COMMENT=		Secure IMAP and POP3 server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:S/.1$//}
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL= 	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-ssldir=${SSLCERTS}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

RCD_SCRIPTS=	dovecot

DOVECOT_USER?=	dovecot
DOVECOT_GROUP?=	dovecot
PKG_GROUPS=	${DOVECOT_GROUP}
PKG_USERS=	${DOVECOT_USER}:${DOVECOT_GROUP}::Dovecot\\ IMAP/POP3\\ user

EGDIR=		${PREFIX}/share/examples/dovecot
CONF_FILES=	${EGDIR}/dovecot.conf.default ${PKG_SYSCONFDIR}/dovecot.conf

INSTALLATION_DIRS=	libexec/dovecot sbin share/doc/dovecot		\
			share/examples/dovecot

post-configure:
	@cd ${WRKSRC};							\
	for i in dovecot-example.conf; do				\
		${SED} ${FILES_SUBST_SED} $$i > $$i.new;		\
		${MV} -f $$i.new $$i;					\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dovecot-example.conf	\
		${EGDIR}/dovecot.conf.default
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EGDIR}

.include "../../mk/bsd.pkg.mk"
