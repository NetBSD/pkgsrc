# $NetBSD: Makefile,v 1.7 2002/01/02 22:19:38 jlam Exp $

PKGNAME=	courier-imap-${BASE_VERS}
PKGREVISION?=	# empty
COMMENT=	IMAP server for access to Maildir-style mailboxes

DEPENDS+=	courier-maildirmake>=0.3:../../mail/courier-maildirmake

USE_BUILDLINK_ONLY=	yes
USE_PERL5=		yes
REPLACE_PERL=		sysconftool

INSTALL_TARGET=		install-strip

.include "../../scratch/courier-imap/Makefile.common"

GEN_FILES=	authdaemonrc imapd imapd-ssl pop3d pop3d-ssl
SSLCNF_FILES=	imapd.cnf pop3d.cnf
CONF_FILES=	${EGDIR}/quotawarnmsg.example ${PKG_SYSCONFDIR}/quotawarnmsg
RCD_SCRIPTS=	courierimap courierimaps courierpop courierpops
OWN_DIRS_PERMS=	/var/authdaemon ${ROOT_USER} ${ROOT_GROUP} 700

CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
.for FILE in ${SSLCNF_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
FILES_SUBST+=		SSLCERTS=${SSLCERTS}
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

pre-configure:
	cd ${WRKSRC}; for file in					\
		imap/imapd.dist.in imap/imapd-ssl.dist.in		\
		imap/pop3d.dist.in imap/pop3d-ssl.dist.in		\
		imap/imapd.cnf.in imap/pop3d.cnf.in			\
		imap/mkimapdcert.in imap/mkpop3dcert.in;		\
	do								\
		${SED}	-e "s|^IMAPDSTART=.*|IMAPDSTART=YES|g"		\
			-e "s|^IMAPDSSLSTART=.*|IMAPDSSLSTART=YES|g"	\
			-e "s|^POP3DSTART=.*|POP3DSTART=YES|g"		\
			-e "s|^POP3DSSLSTART=.*|POP3DSSLSTART=YES|g"	\
			-e "s|@datadir@/imapd.pem|${SSLCERTS}/imapd.pem|g" \
			-e "s|@datadir@/imapd.rand|@sysconfdir@/imapd.rand|g" \
			-e "s|@datadir@/pop3d.pem|${SSLCERTS}/pop3d.pem|g" \
			-e "s|@datadir@/pop3d.rand|@sysconfdir@/pop3d.rand|g" \
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	@for file in ${RCD_SCRIPTS}; do					\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${file}.sh	\
			> ${WRKDIR}/$${file}.sh;			\
		${INSTALL_SCRIPT} ${WRKDIR}/$${file}.sh			\
			${PREFIX}/etc/rc.d/$${file};			\
	done
	${INSTALL_DATA_DIR} ${EGDIR} ${DOCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/imap/BUGS				\
		${DOCDIR}/BUGS.imap
	${INSTALL_DATA} ${WRKSRC}/imap/README				\
		${DOCDIR}/README.imap
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirquota.txt	\
		${DOCDIR}/README.maildirquota
	${INSTALL_DATA} ${WRKSRC}/maildir/README.sharedfolders.txt	\
		${DOCDIR}/README.sharedfolders
	for file in authdaemonrc.dist; do				\
		${INSTALL_DATA} ${PKG_SYSCONFDIR}/$${file} ${EGDIR};	\
		${RM} -f ${PKG_SYSCONFDIR}/$${file};			\
	done
	cd ${WRKSRC}; ${INSTALL_DATA} imap/imapd.pam imap/pop3d.pam ${EGDIR}

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
