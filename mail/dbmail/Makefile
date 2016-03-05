# $NetBSD: Makefile,v 1.51 2016/03/05 11:28:47 jperkin Exp $

DISTNAME=	dbmail-3.2.3
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=pjstevns/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dbmail.org/
COMMENT=	Store and retrieve mail messages in a database
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake pkg-config pax
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log
CONFIGURE_ARGS+=	--with-pkglibdir=${PREFIX}/lib/dbmail
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run
CONFIGURE_ARGS+=	--with-zdb=${BUILDLINK_PREFIX.libzdb}

BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/dbmail
CONF_FILES_PERMS+=	${EGDIR}/dbmail.conf ${PKG_SYSCONFDIR}/dbmail.conf \
			  ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0640
RCD_SCRIPTS=		dbmail dbmailimapd dbmaillmtpd dbmailpop3d
DATADIR=		${PREFIX}/share/dbmail

MESSAGE_SUBST+=		DATADIR=${DATADIR}

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	do-configure
SUBST_FILES.sysconf=	man/dbmail-imapd.8 man/dbmail-lmtpd.8 man/dbmail-pop3d.8
SUBST_FILES.sysconf+=	man/dbmail-smtp.1 man/dbmail-users.8 man/dbmail-util.8
SUBST_FILES.sysconf+=	man/dbmail.1 man/dbmail.conf.5 man/dbmail-export.8
SUBST_FILES.sysconf+=	man/dbmail-sievecmd.8 mail/dbmail-timsieved.8
SUBST_SED.sysconf=	-e 's|/etc/dbmail\.conf|${PKG_SYSCONFDIR}/dbmail.conf|g'
SUBST_MESSAGE.sysconf=	Fixing sysconf paths.

INSTALLATION_DIRS=	lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin ${EGDIR} ${DATADIR}/sql

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${DESTDIR}${EGDIR}
.for f in mysql postgresql sqlite
	cd ${WRKSRC}/sql && pax -rw ${f} ${DESTDIR}${DATADIR}/sql/.
.endfor

.include "options.mk"

.include "../../databases/libzdb/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
