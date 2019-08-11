# $NetBSD: Makefile,v 1.81 2019/08/11 13:21:42 wiz Exp $

DISTNAME=	sqwebmail-5.5.3
PKGREVISION=	9
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Webmail CGI for access to maildir-style mailboxes
HOMEPAGE=	http://www.courier-mta.org/sqwebmail/

DEPENDS+=	courier-maildir>=${COURIER_VERSION}:../../mail/courier-maildir
DEPENDS+=	maildrop>=2.5.0:../../mail/maildrop

USE_TOOLS+=		env gmake gzip:run perl:run
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqwebmail
PKG_SUPPORTED_OPTIONS=	fam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif

.include "../../mail/courier-mta/Makefile.common"

INSTALL_AM_MAKEFLAGS=	sysconfdir=${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

SQWEBMAIL_STATEDIR=	${COURIER_STATEDIR}/sqwebmail
SQWEBMAIL_CACHEDIR=	${SQWEBMAIL_STATEDIR}/logincache
SQWEBMAIL_CALENDARDIR=	${SQWEBMAIL_STATEDIR}/calendar
SQWEBMAIL_IMAGEDIR=	${PREFIX}/share/courier/sqwebmail/images
SQWEBMAIL_IMAGEURL?=	/sqwebmail
BUILD_DEFS+=		SQWEBMAIL_IMAGEURL
FILES_SUBST+=		SQWEBMAIL_STATEDIR=${SQWEBMAIL_STATEDIR}
FILES_SUBST+=		SQWEBMAIL_CACHEDIR=${SQWEBMAIL_CACHEDIR}
FILES_SUBST+=		SQWEBMAIL_CALENDARDIR=${SQWEBMAIL_CALENDARDIR}
FILES_SUBST+=		ROOT_USER=${REAL_ROOT_USER}
MESSAGE_SUBST+=		IMAGEDIR=${SQWEBMAIL_IMAGEDIR}
MESSAGE_SUBST+=		IMAGEURL=${SQWEBMAIL_IMAGEURL}

SENDMAIL?=		/usr/sbin/sendmail
MIME_TYPES=		${PKG_SYSCONFDIR}/mime.types:${PKG_SYSCONFBASEDIR}/httpd/mime.types:${PREFIX}/etc/mime.types:/etc/mime.types

# This is used by the sqwebmail configure script to set the location of
# the sqwebmaild socket file and lockfile.
CONFIGURE_ARGS+=	--localstatedir=${SQWEBMAIL_STATEDIR}

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/courier
CONFIGURE_ARGS+=	--program-transform-name='s/\.rc$$//'

CONFIGURE_ARGS+=	--enable-cgibindir=${LIBEXECDIR}/webmail
CONFIGURE_ARGS+=	--enable-https=auto
CONFIGURE_ARGS+=	--enable-imagedir=${SQWEBMAIL_IMAGEDIR}
CONFIGURE_ARGS+=	--enable-imageurl=${SQWEBMAIL_IMAGEURL:Q}
CONFIGURE_ARGS+=	--enable-mimetypes=${MIME_TYPES:Q}
CONFIGURE_ARGS+=	--with-cachedir=${SQWEBMAIL_CACHEDIR}
CONFIGURE_ARGS+=	--with-cacheowner=${REAL_ROOT_USER}
CONFIGURE_ARGS+=	--with-calendardir=${SQWEBMAIL_CALENDARDIR}
CONFIGURE_ARGS+=	--with-ispell="${PREFIX}/bin/ispell"
CONFIGURE_ARGS+=	--with-mailer="${SENDMAIL} -oi -t"
CONFIGURE_ARGS+=	--with-mailgroup=${COURIER_GROUP}
CONFIGURE_ARGS+=	--with-piddir=${COURIER_STATEDIR}/tmp
CONFIGURE_ARGS+=	--without-ldapaddressbook --without-ldapaliasd

CONFIGURE_ENV+=		GZIP=${TOOLS_PATH.gzip}
CONFIGURE_ENV+=		GPG=${PREFIX}/bin/gpg

REQD_DIRS+=		${DATADIR} ${DOCDIR} ${EGDIR} ${LIBEXECDIR}
REQD_DIRS_PERMS+=	${LIBEXECDIR}/webmail				\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
MAKE_DIRS+=		${COURIER_STATEDIR}
MAKE_DIRS_PERMS+=	${COURIER_STATEDIR}/tmp				\
			${COURIER_USER} ${COURIER_GROUP} 0770
OWN_DIRS+=		${SQWEBMAIL_STATEDIR}
OWN_DIRS_PERMS=		${SQWEBMAIL_CACHEDIR}				\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}			\
			${REAL_ROOT_USER} ${COURIER_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/public			\
			${REAL_ROOT_USER} ${COURIER_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/private		\
			${REAL_ROOT_USER} ${COURIER_GROUP} 0750
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/localcache		\
			${REAL_ROOT_USER} ${COURIER_GROUP} 0700

.for _file_ in calendarmode ldapaddressbook.dist sqwebmaild.dist
CONF_FILES_PERMS+=	${EGDIR}/${_file_}				\
			${PKG_SYSCONFDIR}/${_file_:S/.dist$//}		\
			${COURIER_FILE_PERMS}
.endfor
.for _file_ in cleancache.pl sendit.sh
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
# the webmail directory, so fix it back to the right value.
fix-perms:
	${CHMOD} 0700 ${DESTDIR}${LIBEXECDIR}/webmail

post-install: fix-perms
	${LN} -fs ${PREFIX}/share/courier/sqwebmail/webgpg		\
		${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/gpglib/mimegpg			\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gpglib/mimegpg.1			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/gpglib/mimegpg.html			\
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/calendarmode				\
		${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/sqwebmail.pamconf		\
		${DESTDIR}${EGDIR}/webmail.authpam
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/README.logindomainlist.html		\
		${DESTDIR}${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/INSTALL.html				\
		${DESTDIR}${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/gpglib/README.html			\
		${DESTDIR}${DOCDIR}/sqwebmail/README.gpg.html
	${INSTALL_DATA} ${WRKSRC}/pcp/README.html			\
		${DESTDIR}${DOCDIR}/pcp_README.html
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/BUGS.html			\
		${DESTDIR}${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/SECURITY.html		\
		${DESTDIR}${DOCDIR}/sqwebmail

.include "../../mk/bsd.pkg.mk"
