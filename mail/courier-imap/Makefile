# $NetBSD: Makefile,v 1.93 2024/02/12 21:36:08 hans Exp $

DISTNAME=	courier-imap-5.2.6
PKGREVISION=	
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IMAP server for access to maildir-style mailboxes
HOMEPAGE=	https://www.courier-mta.org/imap/

DEPENDS+=	courier-maildir>=1.3.5:../../mail/courier-maildir
DEPENDS+=	couriertcpd>=1.3.5:../../net/couriertcpd

USE_TOOLS+=		env gmake perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

LIBS.SunOS+=		-lnsl

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
SUBST_FILES.courier=	libs/imap/imapd-ssl.dist.in
SUBST_FILES.courier+=	libs/imap/imapd.8.in
SUBST_FILES.courier+=	libs/imap/imapd.dist.in
SUBST_FILES.courier+=	libs/imap/mkpop3dcert.html.in
SUBST_FILES.courier+=	libs/imap/pop3d-ssl.dist.in
SUBST_FILES.courier+=	libs/imap/pop3d.dist.in
SUBST_FILES.courier+=	imapd-ssl.rc.in
SUBST_FILES.courier+=	imapd.rc.in
SUBST_FILES.courier+=	pop3d-ssl.rc.in
SUBST_FILES.courier+=	pop3d.rc.in
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

# configure: Cannot obtain information for user courier: Undefined error: 0
NOT_FOR_UNPRIVILEGED=	yes

.include "../../security/courier-authlib/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/libs/imap/BUGS.html ${DESTDIR}${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/libs/imap/README.proxy.html ${DESTDIR}${DOCDIR}/imap
	${INSTALL_DATA} ${WRKSRC}/libs/imap/courierpop3d.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/libs/imap/imapd.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/libs/imap/makeimapaccess.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/libs/imap/mkdhparams.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/libs/imap/mkimapdcert.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/libs/imap/mkpop3dcert.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/libs/imap/imapd.pam ${DESTDIR}${EGDIR}/imap.authpam
	${INSTALL_DATA} ${WRKSRC}/libs/imap/pop3d.pam ${DESTDIR}${EGDIR}/pop3.authpam

.include "../../mk/bsd.pkg.mk"
