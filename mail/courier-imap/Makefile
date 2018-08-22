# $NetBSD: Makefile,v 1.83 2018/08/22 09:45:23 wiz Exp $

DISTNAME=	courier-imap-4.10.0
PKGREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IMAP server for access to maildir-style mailboxes
HOMEPAGE=	http://www.courier-mta.org/imap/

DEPENDS+=	courier-maildir>=0.65.0:../../mail/courier-maildir
DEPENDS+=	couriertcpd>=0.65.0:../../net/couriertcpd

USE_TOOLS+=		env gmake perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

.include "options.mk"

.include "../../mail/courier-mta/Makefile.common"

CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--libexecdir=${LIBEXECDIR}
CONFIGURE_ARGS+=	--with-mailuser=${REAL_ROOT_USER}
CONFIGURE_ARGS+=	--with-piddir=${COURIER_STATEDIR}/tmp
CONFIGURE_ARGS+=	--program-transform-name='s/\.rc$$//'
CONFIGURE_ENV+=		CERTTOOL=${COURIER_CERTTOOL:Q}
CONFIGURE_ENV+=		OPENSSL=${COURIER_OPENSSL:Q}

# The rfc1035 and tcpd bits are built and installed by net/couriertcpd.
# However, we still need to build in these directories because there
# are some convenience libraries built and used by other parts of the
# imap code.  We configure without IPv6 support because those necessary
# convenience libraries don't have any IPv6 code, and we want to avoid
# breakage due to IPv6 mis-detection.
CONFIGURE_ARGS+=	--without-ipv6

INSTALL_AM_MAKEFLAGS=	sysconfdir=${EGDIR:Q}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

REQD_DIRS+=		${DATADIR} ${DOCDIR} ${EGDIR} ${LIBEXECDIR}
MAKE_DIRS+=		${COURIER_STATEDIR}
MAKE_DIRS_PERMS+=	${COURIER_STATEDIR}/tmp				\
			${COURIER_USER} ${COURIER_GROUP} 0770

.for _file_ in		imapd.cnf imapd.dist imapd-ssl.dist		\
			pop3d.cnf pop3d.dist pop3d-ssl.dist
CONF_FILES_PERMS+=	${EGDIR}/${_file_}				\
			${PKG_SYSCONFDIR}/${_file_:S/.dist$//}		\
			${COURIER_FILE_PERMS}
.endfor
RCD_SCRIPTS=		courierimap courierimaps courierpop courierpops
SMF_METHODS=		courier-imap

SUBST_CLASSES+=		courier
SUBST_FILES.courier=	imap/imapd-ssl.dist.in imap/imapd.8.in		\
			imap/imapd.cnf.openssl.in imap/imapd.dist.in	\
			imap/mkimapdcert.8.in imap/mkimapdcert.html.in	\
			imap/mkimapdcert.in imapd-ssl.rc.in imapd.rc.in
SUBST_FILES.courier+=	imap/courierpop3d.8.in imap/mkpop3dcert.8.in	\
			imap/mkpop3dcert.html.in imap/mkpop3dcert.in	\
			imap/pop3d-ssl.dist.in imap/pop3d.cnf.openssl.in \
			imap/pop3d.dist.in pop3d-ssl.rc.in pop3d.rc.in
SUBST_SED.courier=	-e "s|^IMAPDSTART=.*|IMAPDSTART=YES|g"
SUBST_SED.courier+=	-e "s|^IMAPDSSLSTART=.*|IMAPDSSLSTART=YES|g"
SUBST_SED.courier+=	-e "s|^POP3DSTART=.*|POP3DSTART=YES|g"
SUBST_SED.courier+=	-e "s|^POP3DSSLSTART=.*|POP3DSSLSTART=YES|g"
SUBST_SED.courier+=	-e "s|@mydatadir@|@sysconfdir@|g"
SUBST_SED.courier+=	-e "s|@datadir@/imapd.pem|@sysconfdir@/imapd.pem|g"
SUBST_SED.courier+=	-e "s|@datadir@/imapd.rand|@sysconfdir@/imapd.rand|g"
SUBST_SED.courier+=	-e "s|@datadir@/pop3d.pem|@sysconfdir@/pop3d.pem|g"
SUBST_SED.courier+=	-e "s|@datadir@/pop3d.rand|@sysconfdir@/pop3d.rand|g"
SUBST_SED.courier+=	-e "s|@libexecdir@/couriertcpd|@sbindir@/couriertcpd|g"
SUBST_SED.courier+=	-e "s|@sbindir@/imaplogin|@libexecdir@/imaplogin|g"
SUBST_SED.courier+=	-e "s|@sbindir@/pop3login|@libexecdir@/courierpop3login|g"
SUBST_SED.courier+=	-e "s|@bindir@/pop3d|@libexecdir@/courierpop3d|g"
SUBST_STAGE.courier=	pre-configure

.include "../../security/courier-authlib/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/imap/BUGS.html ${DESTDIR}${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/imap/README.html ${DESTDIR}${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/imap/README.proxy.html ${DESTDIR}${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/imap/courierpop3d.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/imap/imapd.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/imap/mkimapdcert.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/imap/mkpop3dcert.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/imap/imapd.pam ${DESTDIR}${EGDIR}/imap.authpam
	${INSTALL_DATA} ${WRKSRC}/imap/pop3d.pam ${DESTDIR}${EGDIR}/pop3.authpam

.include "../../mk/bsd.pkg.mk"
