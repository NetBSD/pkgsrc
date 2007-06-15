# $NetBSD: Makefile,v 1.52 2007/06/15 18:15:19 jlam Exp $

DISTNAME=	sqwebmail-5.1.2
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Webmail CGI for access to maildir-style mailboxes
HOMEPAGE=	http://www.courier-mta.org/sqwebmail/

DEPENDS+=	courier-maildir>=0.53.1:../../mail/courier-maildir
DEPENDS+=	maildrop>=2.0.1:../../mail/maildrop

USE_TOOLS+=		env gmake gzip:run perl:run
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKG_SUPPORTED_OPTIONS+=	fam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif

# PKGNAME is a parameter to the following file.
PKGNAME=		${DISTNAME}
.include "../../mail/courier-mta/Makefile.common"

INSTALL_AM_MAKEFLAGS=	sysconfdir=${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

SQWEBMAIL_STATEDIR=	${COURIER_STATEDIR}/sqwebmail
SQWEBMAIL_CACHEDIR=	${SQWEBMAIL_STATEDIR}/logincache
SQWEBMAIL_CALENDARDIR=	${SQWEBMAIL_STATEDIR}/calendar
SQWEBMAIL_IMAGEDIR=	${PREFIX}/share/courier/sqwebmail/images
SQWEBMAIL_IMAGEURL?=	/sqwebmail
BUILD_DEFS+=		SQWEBMAIL_IMAGEURL
FILES_SUBST+=		SQWEBMAIL_STATEDIR=${SQWEBMAIL_STATEDIR:Q}
FILES_SUBST+=		SQWEBMAIL_CACHEDIR=${SQWEBMAIL_CACHEDIR:Q}
FILES_SUBST+=		SQWEBMAIL_CALENDARDIR=${SQWEBMAIL_CALENDARDIR:Q}
FILES_SUBST+=		ROOT_USER=${ROOT_USER:Q}
MESSAGE_SUBST+=		IMAGEDIR=${SQWEBMAIL_IMAGEDIR}
MESSAGE_SUBST+=		IMAGEURL=${SQWEBMAIL_IMAGEURL}

SENDMAIL?=		/usr/sbin/sendmail
MIME_TYPES=		${PKG_SYSCONFDIR}/mime.types:${PKG_SYSCONFBASEDIR}/httpd/mime.types:${PREFIX}/etc/mime.types:/etc/mime.types

# This is used by the sqwebmail configure script to set the location of
# the sqwebmaild socket file and lockfile.
#
CONFIGURE_ARGS+=	--localstatedir=${SQWEBMAIL_STATEDIR:Q}

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/courier
CONFIGURE_ARGS+=	--program-transform-name='s/\.rc$$//'

CONFIGURE_ARGS+=	--enable-cgibindir=${PREFIX}/libexec/courier/cgi-bin
CONFIGURE_ARGS+=	--enable-https=auto
CONFIGURE_ARGS+=	--enable-imagedir=${SQWEBMAIL_IMAGEDIR:Q}
CONFIGURE_ARGS+=	--enable-imageurl=${SQWEBMAIL_IMAGEURL:Q}
CONFIGURE_ARGS+=	--enable-mimetypes=${MIME_TYPES:Q}
CONFIGURE_ARGS+=	--with-cachedir=${SQWEBMAIL_CACHEDIR:Q}
CONFIGURE_ARGS+=	--with-cacheowner=${ROOT_USER:Q}
CONFIGURE_ARGS+=	--with-calendardir=${SQWEBMAIL_CALENDARDIR:Q}
CONFIGURE_ARGS+=	--with-ispell="${LOCALBASE}/bin/ispell"
CONFIGURE_ARGS+=	--with-mailer="${SENDMAIL} -oi -t"
CONFIGURE_ARGS+=	--with-mailgroup=${COURIER_GROUP:Q}
CONFIGURE_ARGS+=	--with-piddir=${VARBASE}/run

CONFIGURE_ENV+=		GZIP=${TOOLS_PATH.gzip:Q}
CONFIGURE_ENV+=		GPG="${LOCALBASE}/bin/gpg"
CONFIGURE_ENV+=		ldapsearch="${LOCALBASE}/bin/ldapsearch"

REQD_DIRS+=		${DATADIR} ${DOCDIR} ${EGDIR} ${LIBEXECDIR}
REQD_DIRS_PERMS+=	${LIBEXECDIR}/cgi-bin				\
			${ROOT_USER} ${ROOT_GROUP} 0700
MAKE_DIRS+=		${VARBASE}/run ${LOCALSTATEDIR}
OWN_DIRS+=		${SQWEBMAIL_STATEDIR}
OWN_DIRS+=		${SQWEBMAIL_CACHEDIR}
OWN_DIRS_PERMS=		${SQWEBMAIL_CALENDARDIR}			\
			${ROOT_USER} ${COURIER_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/public			\
			${ROOT_USER} ${COURIER_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/private		\
			${ROOT_USER} ${COURIER_GROUP} 0750
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/localcache		\
			${ROOT_USER} ${COURIER_GROUP} 0700

.for _file_ in calendarmode ldapaddressbook.dist sqwebmaild.dist
CONF_FILES_PERMS+=	${EGDIR}/${_file_}				\
			${PKG_SYSCONFDIR}/${_file_:S/.dist$//}		\
			${COURIER_FILE_PERMS}
.endfor
.for _file_ in cleancache.pl ldapsearch sendit.sh
CONF_FILES_PERMS+=	${PREFIX}/share/courier/sqwebmail/${_file_}	\
			${PKG_SYSCONFDIR}/${_file_}			\
			${COURIER_SCRIPT_PERMS}
.endfor
SPECIAL_PERMS=		${LIBEXECDIR}/sqwebpasswd			\
			${COURIER_USER} ${COURIER_GROUP} 2555

RCD_SCRIPTS=		sqwebmail
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 sbin

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/courier-authlib/buildlink3.mk"

# Default to non-groupware calendar-mode.
post-build:
	${ECHO} "local" > ${WRKDIR}/calendarmode

# The sqwebmail install target incorrectly overwrites the mode on
# cgi-bin directory, so fix it back to the right value.
#
fix-perms:
	${CHMOD} 0700 ${LIBEXECDIR}/cgi-bin

post-install: fix-perms
	${LN} -s ${PREFIX}/share/courier/sqwebmail/webgpg ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/gpglib/mimegpg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gpglib/mimegpg.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/gpglib/mimegpg.html ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/calendarmode ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/sqwebmail.pamconf		\
		${EGDIR}/webmail.authpam
	${INSTALL_DATA_DIR} ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/README.logindomainlist.html		\
		${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/INSTALL.html ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/gpglib/README.html			\
		${DOCDIR}/sqwebmail/README.gpg.html
	${INSTALL_DATA} ${WRKSRC}/pcp/README.html			\
		${DOCDIR}/pcp_README.html
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/BUGS.html ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/SECURITY.html ${DOCDIR}/sqwebmail

.include "../../mk/bsd.pkg.mk"
