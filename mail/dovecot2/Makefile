# $NetBSD: Makefile,v 1.110 2022/01/08 11:41:21 schmonz Exp $

.include "../../mail/dovecot2/Makefile.common"

RCD_SCRIPTS=		dovecot
SMF_NAME=		dovecot

DOVECOT_USER?=		dovecot
DOVECOT_GROUP?=		dovecot
DOVENULL_USER?=		dovenull
DOVENULL_GROUP?=	dovenull
PKG_GROUPS=		${DOVECOT_GROUP} ${DOVENULL_GROUP}
PKG_USERS=		${DOVECOT_USER}:${DOVECOT_GROUP}	\
			${DOVENULL_USER}:${DOVENULL_GROUP}
PKG_GROUPS_VARS=	DOVECOT_GROUP DOVENULL_GROUP
PKG_USERS_VARS=		DOVECOT_USER DOVENULL_USER

PKG_GECOS.${DOVECOT_USER}=	Dovecot IMAP/POP3 user
PKG_GECOS.${DOVENULL_USER}=	Dovecot login user

EGDIR=			${PREFIX}/share/examples/dovecot

CNFS_cmd=		${SED} -ne "s,^share/examples/dovecot/,,p" PLIST
CNFS=			${CNFS_cmd:sh}
CONF_FILES=		${EGDIR}/dovecot.conf ${PKG_SYSCONFDIR}/dovecot/dovecot.conf
.for file in ${CNFS}
CONF_FILES+=		${EGDIR}/${file:Q} ${PKG_SYSCONFDIR}/dovecot/${file:Q}
.endfor

INSTALLATION_DIRS+=	libexec/dovecot sbin share/doc/dovecot
INSTALLATION_DIRS+=	share/examples/dovecot share/examples/dovecot/conf.d
OWN_DIRS=		${PKG_SYSCONFDIR}/dovecot/
OWN_DIRS+=		${PKG_SYSCONFDIR}/dovecot/conf.d

REPLACE_BASH+=		src/util/dovecot-sysreport
REPLACE_BASH+=		src/util/health-check.sh

.PHONY: enable-manz-by-replacing-roff-includes-with-symlinks
enable-manz-by-replacing-roff-includes-with-symlinks:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR} && \
	for i in $$(${GREP} -lr ^\\.so .); do \
		j=$$(${SED} -e 's|^\.so |../|' < $${i}); \
		${RM} -f $${i} && ${LN} -s $${j} $${i}; \
	done

post-install: enable-manz-by-replacing-roff-includes-with-symlinks
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
