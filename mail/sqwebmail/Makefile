# $NetBSD: Makefile,v 1.31 2005/05/13 02:35:40 jlam Exp $

DISTNAME=	sqwebmail-5.0.1
PKGBASE=	${DISTNAME:C/-[^-]*$//}
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@NetBSD.org
COMMENT=	webmail CGI for access to maildir-style mailboxes
HOMEPAGE=	http://www.courier-mta.org/sqwebmail/

DEPENDS+=	courier-maildir>=0.48.2:../../mail/courier-maildir
DEPENDS+=	maildrop>=1.8.0:../../mail/maildrop

USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PERL5=		yes

.include "../../mail/courier-maildir/Makefile.common"
.include "../../security/courier-authlib/Makefile.common"

INSTALL_AM_MAKEFLAGS=	sysconfdir=${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

SQWEBMAIL_STATEDIR=	${VARBASE}/sqwebmail
SQWEBMAIL_CACHEDIR=	${SQWEBMAIL_STATEDIR}/logincache
SQWEBMAIL_CALENDARDIR=	${SQWEBMAIL_STATEDIR}/calendar
SQWEBMAIL_IMAGEDIR=	${PREFIX}/share/courier/sqwebmail/images
SQWEBMAIL_IMAGEURL?=	/sqwebmail
BUILD_DEFS+=		SQWEBMAIL_IMAGEURL
FILES_SUBST+=		SQWEBMAIL_STATEDIR=${SQWEBMAIL_STATEDIR:Q}
MESSAGE_SUBST+=		IMAGEDIR=${SQWEBMAIL_IMAGEDIR}
MESSAGE_SUBST+=		IMAGEURL=${SQWEBMAIL_IMAGEURL}

SENDMAIL?=		/usr/sbin/sendmail
MIME_TYPES=		${PKG_SYSCONFDIR}/mime.types:${PKG_SYSCONFBASEDIR}/httpd/mime.types:${PREFIX}/etc/mime.types:/etc/mime.types

# This is used by the sqwebmail configure script to set the location of
# the sqwebmaild socket file and lockfile.
#
CONFIGURE_ARGS+=	--localstatedir=${SQWEBMAIL_STATEDIR}

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/courier
CONFIGURE_ARGS+=	--program-transform-name='s/\.rc$$//'

CONFIGURE_ARGS+=	--enable-cgibindir=${PREFIX}/libexec/cgi-bin
CONFIGURE_ARGS+=	--enable-https=auto
CONFIGURE_ARGS+=	--enable-imagedir=${SQWEBMAIL_IMAGEDIR}
CONFIGURE_ARGS+=	--enable-imageurl=${SQWEBMAIL_IMAGEURL}
CONFIGURE_ARGS+=	--enable-mimetypes="${MIME_TYPES}"
CONFIGURE_ARGS+=	--with-cachedir=${SQWEBMAIL_CACHEDIR}
CONFIGURE_ARGS+=	--with-cacheowner=${ROOT_USER}
CONFIGURE_ARGS+=	--with-calendardir=${SQWEBMAIL_CALENDARDIR}
CONFIGURE_ARGS+=	--with-ispell="${LOCALBASE}/bin/ispell"
CONFIGURE_ARGS+=	--with-mailer="${SENDMAIL} -oi -t"
CONFIGURE_ARGS+=	--with-mailgroup=${COURIER_GROUP}
CONFIGURE_ARGS+=	--with-piddir=${VARBASE}/run

CONFIGURE_ENV+=		GPG="${LOCALBASE}/bin/gpg"
CONFIGURE_ENV+=		ldapsearch="${LOCALBASE}/bin/ldapsearch"

MAKE_DIRS=		${VARBASE}/run
OWN_DIRS=		${SQWEBMAIL_STATEDIR}
OWN_DIRS+=		${SQWEBMAIL_CACHEDIR}
OWN_DIRS_PERMS=		${SQWEBMAIL_CALENDARDIR}			\
			${ROOT_USER} ${COURIER_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/public			\
			${ROOT_USER} ${COURIER_GROUP} 0755
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/private		\
			${ROOT_USER} ${COURIER_GROUP} 0750
OWN_DIRS_PERMS+=	${SQWEBMAIL_CALENDARDIR}/localcache		\
			${ROOT_USER} ${COURIER_GROUP} 0700

GEN_FILES=		ldapaddressbook sqwebmaild
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

.for FILE in ${GEN_FILES}
CONF_FILES+=		${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}
.endfor
CONF_FILES+=		${EGDIR}/calendarmode ${PKG_SYSCONFDIR}/calendarmode
CONF_FILES_PERMS=	# empty
.for FILE in cleancache.pl ldapsearch sendit.sh
CONF_FILES_PERMS+=	${PREFIX}/share/courier/sqwebmail/${FILE}	\
			${PKG_SYSCONFDIR}/${FILE}			\
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor
SPECIAL_PERMS=		libexec/courier/sqwebpasswd			\
			${COURIER_USER} ${COURIER_GROUP} 2755
RCD_SCRIPTS=		sqwebmail

SUBST_CLASSES+=		courier
SUBST_MESSAGE.courier=	"Substituting for @mailuser@ and @mailgroup@."
SUBST_FILES.courier=	sqwebmail/Makefile.in
SUBST_SED.courier=	-e "s|@mailuser@|${COURIER_USER}|g"		\
			-e "s|@mailgroup@|${COURIER_GROUP}|g"
SUBST_STAGE.courier=	pre-configure

INSTALLATION_DIRS=	bin man/man1 sbin

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/courier-authlib/buildlink3.mk"

# Default to non-groupware calendar-mode.
post-build:
	${ECHO} "local" > ${WRKDIR}/calendarmode

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gpglib/webgpg ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/gpglib/mimegpg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gpglib/mimegpg.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/calendarmode ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/sqwebmail.pamconf		\
		${EGDIR}/webmail.pam
	${INSTALL_DATA_DIR} ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/README.logindomainlist.html		\
		${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/INSTALL.html ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/gpglib/README.html			\
		${DOCDIR}/sqwebmail/README.gpg.html
	${INSTALL_DATA} ${WRKSRC}/pcp/README.html			\
		${DOCDIR}/sqwebmail/README.pcp.html
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/BUGS.html ${DOCDIR}/sqwebmail
	${INSTALL_DATA} ${WRKSRC}/sqwebmail/SECURITY.html ${DOCDIR}/sqwebmail

.include "../../mk/bsd.pkg.mk"
