# $NetBSD: Makefile,v 1.18 2004/02/24 00:14:33 jlam Exp $

DISTNAME=	sqwebmail-3.6.2
CATEGORIES=	www
COMMENT=	webmail CGI for access to local Maildir-style mailboxes
HOMEPAGE=	http://www.inter7.com/sqwebmail/

DEPENDS+=	courier-auth>=${BASE_VERS}:../../mail/courier-auth
DEPENDS+=	courier-maildirmake>=${BASE_VERS}:../../mail/courier-maildirmake

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_PERL5=		yes
REPLACE_PERL=		sysconftool

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.include "../courier-auth/Makefile.common"

.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL:M-s)
INSTALL_TARGET=         install-strip
.endif
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

STATEDIR=		/var/sqwebmail
CACHEDIR=		${STATEDIR}/cache
CALENDARDIR=		${STATEDIR}/calendar
SQWEBMAIL_HTMLDIR=	${DATADIR}/sqwebmail/html
SQWEBMAIL_IMAGEDIR=	${DATADIR}/sqwebmail/images
SQWEBMAIL_IMAGEURL?=	/sqwebmail
BUILD_DEFS+=		SQWEBMAIL_IMAGEURL

SENDMAIL?=		/usr/sbin/sendmail

# This is used by the sqwebmail configure script to set the location of
# the sqwebmaild socket file, lockfile, and pidfile.
#
CONFIGURE_ARGS+=	--localstatedir=${STATEDIR}

CONFIGURE_ARGS+=	--with-cachedir=${CACHEDIR}
CONFIGURE_ARGS+=	--with-calendardir=${CALENDARDIR}
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

OWN_DIRS=		${STATEDIR}
OWN_DIRS_PERMS=		${CACHEDIR} ${ROOT_USER} ${ROOT_GROUP} 0755
OWN_DIRS_PERMS+=	${CALENDARDIR} ${ROOT_USER} ${MAIL_GROUP} 0755
OWN_DIRS_PERMS+=	${CALENDARDIR}/public ${ROOT_USER} ${MAIL_GROUP} 0755
OWN_DIRS_PERMS+=	${CALENDARDIR}/private ${ROOT_USER} ${MAIL_GROUP} 0750
OWN_DIRS_PERMS+=	${CALENDARDIR}/localcache ${ROOT_USER} ${MAIL_GROUP} 0700

SYSCONFTOOL=		${PREFIX}/sbin/sqwebmail.sysconftool
GEN_FILES=		ldapaddressbook
FILES_SUBST+=		SYSCONFTOOL=${SYSCONFTOOL:Q}
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}
MESSAGE_SUBST+=		IMAGEDIR=${SQWEBMAIL_IMAGEDIR}
MESSAGE_SUBST+=		IMAGEURL=${SQWEBMAIL_IMAGEURL}

SUPPORT_FILES=		${EGDIR}/authmodulelist ${PKG_SYSCONFDIR}/authmodulelist
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
RCD_SCRIPTS=		pcpd sqwebmaild

.if ${OPSYS} == "SunOS"
.  include "../../databases/db/buildlink3.mk"
.endif
.include "../../devel/gettext-lib/buildlink3.mk"

pre-configure:
	for file in ${WRKSRC}/sqwebmail/Makefile.in; do			\
		${MV} -f $$file $$file.bak;				\
		${SED}	-e "s|@htmldir@|${SQWEBMAIL_HTMLDIR}|g"		\
			-e "s|@scriptdir@|@datadir@/sqwebmail|g"	\
			$$file.bak > $$file;				\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/pcp
	${INSTALL_DATA_DIR} ${HTMLDIR}/sqwebmail
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${SYSCONFTOOL}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${HTMLDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/INSTALL.html ${HTMLDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/gpglib/README.html			\
		${HTMLDIR}/sqwebmail/README.gpg.html
	${INSTALL_DATA} ${WRKSRC}/pcp/README.html			\
		${HTMLDIR}/sqwebmail/README.pcp.html
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/BUGS.html ${HTMLDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/SECURITY.html ${HTMLDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/webmail.authpam ${EGDIR}

.include "../../mk/bsd.pkg.mk"
