# $NetBSD: Makefile,v 1.14 2002/09/19 09:04:11 jlam Exp $

DISTNAME=	courier-imap-1.4.2
PKGREVISION=	1
COMMENT=	IMAP server for access to Maildir-style mailboxes
HOMEPAGE=	http://www.inter7.com/courierimap/

DEPENDS+=	courier-auth>=0.37.1:../../mail/courier-auth
DEPENDS+=	courier-maildirmake>=0.37.1nb1:../../mail/courier-maildirmake

USE_BUILDLINK_ONLY=	yes
USE_PERL5=		yes
REPLACE_PERL=		sysconftool

.include "../../mail/courier-auth/Makefile.common"

CONFIGURE_ENV+=		OPENSSL=${BUILDLINK_PREFIX.openssl}/bin/openssl

.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL:M-s)
INSTALL_TARGET=         install-strip
.endif

SYSCONFTOOL=		${PREFIX}/sbin/imapd.sysconftool
GEN_FILES=		imapd imapd-ssl pop3d pop3d-ssl
SSLCNF_FILES=		imapd.cnf pop3d.cnf
RCD_SCRIPTS=		courierimap courierimaps courierpop courierpops

CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
.for FILE in ${SSLCNF_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

INSTALL_EXTRA_TMPL=	${.CURDIR}/../../mail/courier-auth/INSTALL
FILES_SUBST+=		SYSCONFTOOL=${SYSCONFTOOL:Q}
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
	${INSTALL_DATA_DIR} ${EGDIR} ${DOCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${SYSCONFTOOL}
	${INSTALL_DATA} ${WRKSRC}/imap/BUGS				\
		${DOCDIR}/BUGS.imap
	${INSTALL_DATA} ${WRKSRC}/imap/README				\
		${DOCDIR}/README.imap
	cd ${WRKSRC}; ${INSTALL_DATA} imap/imapd.pam imap/pop3d.pam ${EGDIR}

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
