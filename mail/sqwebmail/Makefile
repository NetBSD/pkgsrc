# $NetBSD: Makefile,v 1.25 2004/10/03 00:12:54 tv Exp $

DISTNAME=	sqwebmail-4.0.5
PKGREVISION=	1
CATEGORIES=	www
COMMENT=	webmail CGI for access to local maildir-style mailboxes
HOMEPAGE=	http://www.inter7.com/sqwebmail/

DEPENDS+=	courier-auth>=${BASE_VERS}:../../mail/courier-auth
DEPENDS+=	courier-maildir>=${BASE_VERS}:../../mail/courier-maildir

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_PERL5=		yes

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../courier-auth/INSTALL

.include "../courier-auth/Makefile.common"

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

SQWEBMAIL_STATEDIR=	${VARBASE}/sqwebmail
SQWEBMAIL_CACHEDIR=	${SQWEBMAIL_STATEDIR}/cache
SQWEBMAIL_CALENDARDIR=	${SQWEBMAIL_STATEDIR}/calendar
SQWEBMAIL_HTMLDIR=	${DATADIR}/sqwebmail/html
SQWEBMAIL_IMAGEDIR=	${DATADIR}/sqwebmail/images
SQWEBMAIL_IMAGEURL?=	/sqwebmail
BUILD_DEFS+=		SQWEBMAIL_IMAGEURL
FILES_SUBST+=		SQWEBMAIL_STATEDIR=${SQWEBMAIL_STATEDIR:Q}

SENDMAIL?=		/usr/sbin/sendmail

# This is used by the sqwebmail configure script to set the location of
# the sqwebmaild socket file, lockfile and pidfile.
#
CONFIGURE_ARGS+=	--localstatedir=${SQWEBMAIL_STATEDIR}

CONFIGURE_ARGS+=	--with-cachedir=${SQWEBMAIL_CACHEDIR}
CONFIGURE_ARGS+=	--with-calendardir=${SQWEBMAIL_CALENDARDIR}
CONFIGURE_ARGS+=	--with-cacheowner=${ROOT_USER}
CONFIGURE_ARGS+=	--with-mailer=${SENDMAIL}
CONFIGURE_ARGS+=	--enable-https=auto
CONFIGURE_ARGS+=	--enable-cgibindir=${PREFIX}/libexec/cgi-bin
CONFIGURE_ARGS+=	--with-htmldir=${SQWEBMAIL_HTMLDIR}
CONFIGURE_ARGS+=	--enable-imagedir=${SQWEBMAIL_IMAGEDIR}
CONFIGURE_ARGS+=	--enable-imageurl=${SQWEBMAIL_IMAGEURL}

MIME_TYPES=		${PKG_SYSCONFDIR}/mime.types:${PKG_SYSCONFBASEDIR}/httpd/mime.types:${PREFIX}/etc/mime.types:/etc/mime.types
CONFIGURE_ARGS+=	--enable-mimetypes="${MIME_TYPES}"
CONFIGURE_ARGS+=	--with-ispell="${LOCALBASE}/bin/ispell"
CONFIGURE_ENV+=		GPG="${LOCALBASE}/bin/gpg"
CONFIGURE_ENV+=		ldapsearch="${LOCALBASE}/bin/ldapsearch"

MAIL_GROUP?=		mail
PKG_GROUPS=             ${MAIL_GROUP}

OWN_DIRS=		${SQWEBMAIL_STATEDIR}
OWN_DIRS_PERMS=		${SQWEBMAIL_CACHEDIR} ${ROOT_USER} ${ROOT_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR} ${ROOT_USER} ${MAIL_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/public ${ROOT_USER} ${MAIL_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/private ${ROOT_USER} ${MAIL_GROUP} 0750
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/localcache ${ROOT_USER} ${MAIL_GROUP} 0700

GEN_FILES=		ldapaddressbook
GEN_FILES+=		sqwebmaild
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}
MESSAGE_SUBST+=		IMAGEDIR=${SQWEBMAIL_IMAGEDIR}
MESSAGE_SUBST+=		IMAGEURL=${SQWEBMAIL_IMAGEURL}

SUPPORT_FILES=		${EGDIR}/calendarmode ${PKG_SYSCONFDIR}/calendarmode
SUPPORT_FILES+=		/dev/null ${PKG_SYSCONFDIR}/nodsn
.for FILE in ${GEN_FILES}
CONF_FILES+=		${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}
.endfor
CONF_FILES_PERMS=	# empty
.for FILE in ldapsearch sendit.sh
CONF_FILES_PERMS+=	${DATADIR}/sqwebmail/${FILE}			\
			${PKG_SYSCONFDIR}/${FILE}			\
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor
RCD_SCRIPTS=		sqwebmail

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"

pre-configure:
	for file in ${WRKSRC}/sqwebmail/Makefile.in; do			\
		${MV} -f $$file $$file.bak;				\
		${SED}	-e "s|@htmldir@|${SQWEBMAIL_HTMLDIR}|g"		\
			-e "s|@scriptdir@|@datadir@/sqwebmail|g"	\
			$$file.bak > $$file;				\
	done

# Default to non-groupware calendar-mode.
post-build:
	${ECHO} "local" > ${WRKDIR}/calendarmode

post-install:
	${LN} -sf ${DATADIR}/sqwebmail/webgpg ${PREFIX}/sbin/webgpg
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/calendarmode ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/webmail.authpam ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/README.logindomainlist.html		\
		${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/INSTALL.html ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/gpglib/README.html			\
		${DOCDIR}/sqwebmail/README.gpg.html
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirfilter.html	\
		${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/pcp/README.html			\
		${DOCDIR}/sqwebmail/README.pcp.html
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/BUGS.html ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/SECURITY.html ${DOCDIR}/sqwebmail

.include "../../mk/bsd.pkg.mk"
