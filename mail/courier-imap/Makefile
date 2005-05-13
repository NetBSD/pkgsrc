# $NetBSD: Makefile,v 1.37 2005/05/13 05:20:48 jlam Exp $

DISTNAME=	courier-imap-4.0.2
PKGBASE=	${DISTNAME:C/-[^-]*$//}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@NetBSD.org
COMMENT=	IMAP server for access to maildir-style mailboxes
HOMEPAGE=	http://www.courier-mta.org/imap/

DEPENDS+=	courier-maildir>=0.48.2:../../mail/courier-maildir

USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PERL5=		build

.include "../../mail/courier-maildir/Makefile.common"

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/courier
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/courier

CONFIGURE_ARGS+=	--with-mailuser=${ROOT_USER}
CONFIGURE_ARGS+=	--with-piddir=${VARBASE}/run
CONFIGURE_ARGS+=	--program-transform-name='s/\.rc$$//'
CONFIGURE_ENV+=		OPENSSL=${SSLBASE}/bin/openssl

INSTALL_AM_MAKEFLAGS=	sysconfdir=${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

GEN_FILES=		imapd imapd-ssl pop3d pop3d-ssl
SSLCNF_FILES=		imapd.cnf pop3d.cnf
FILES_SUBST+=		SSLCERTS=${SSLCERTS}
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
MAKE_DIRS=		${VARBASE}/run
CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES+=		${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}
.endfor
.for FILE in ${SSLCNF_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
RCD_SCRIPTS=		courierimap courierimaps courierpop courierpops

SUBST_CLASSES+=		courier
SUBST_MESSAGE.courier=	"Convert to match courier-mta expectations."
SUBST_FILES.courier=	imap/imapd.dist.in imap/imapd-ssl.dist.in	\
			imap/pop3d.dist.in imap/pop3d-ssl.dist.in	\
			imap/imapd.cnf.in imap/pop3d.cnf.in		\
			imap/mkimapdcert.in imap/mkpop3dcert.in		\
			imap/imapd.8.in imap/courierpop3d.8.in		\
			imapd-ssl.rc.in imapd.rc.in			\
			pop3d-ssl.rc.in pop3d.rc.in
SUBST_SED.courier=	-e "s|^IMAPDSTART=.*|IMAPDSTART=YES|g"		\
			-e "s|^IMAPDSSLSTART=.*|IMAPDSSLSTART=YES|g"	\
			-e "s|^POP3DSTART=.*|POP3DSTART=YES|g"		\
			-e "s|^POP3DSSLSTART=.*|POP3DSSLSTART=YES|g"	\
			-e "s|@datadir@/imapd.pem|${SSLCERTS}/imapd.pem|g" \
			-e "s|@datadir@/imapd.rand|@sysconfdir@/imapd.rand|g" \
			-e "s|@datadir@/pop3d.pem|${SSLCERTS}/pop3d.pem|g" \
			-e "s|@datadir@/pop3d.rand|@sysconfdir@/pop3d.rand|g" \
			-e "s|@libexecdir@/couriertcpd|@sbindir@/couriertcpd|g" \
			-e "s|@sbindir@/imaplogin|@libexecdir@/imaplogin|g" \
			-e "s|@sbindir@/pop3login|@libexecdir@/courierpop3login|g" \
			-e "s|@bindir@/pop3d|@libexecdir@/courierpop3d|g"
SUBST_STAGE.courier=	pre-configure

.include "../../security/courier-authlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/imap/BUGS.html ${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/imap/README.html ${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/imap/README.proxy.html ${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/imap/imapd.pam ${EGDIR}/imap.pam
	${INSTALL_DATA} ${WRKSRC}/imap/pop3d.pam ${EGDIR}/pop3.pam

.include "../../mk/bsd.pkg.mk"
