# $NetBSD: Makefile,v 1.35 2012/12/16 01:52:20 obache Exp $

DISTNAME=	dbmail-2.2.17
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	http://www.dbmail.org/download/2.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dbmail.org/
COMMENT=	Store and retrieve mail messages in a database
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log
CONFIGURE_ARGS+=	--with-pkglibdir=${PREFIX}/lib/dbmail
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run

BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/dbmail
CONF_FILES_PERMS+=	${EGDIR}/dbmail.conf ${PKG_SYSCONFDIR}/dbmail.conf \
			  ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0640
RCD_SCRIPTS=		dbmail dbmailimapd dbmaillmtpd dbmailpop3d
DATADIR=		${PREFIX}/share/dbmail
DOCSDIR=		${PREFIX}/share/doc/dbmail
DOCS=			AUTHORS BUGS COPYING INSTALL NEWS README
DOCS+=			README.aliases README.exim README.ldap
DOCS+=			README.postfix README.qmail README.sieve
DOCS+=			README.smtp README.solaris README.usermap
DOCS+=			THANKS UPGRADING

MESSAGE_SUBST+=		DOCSDIR=${DOCSDIR}
MESSAGE_SUBST+=		DATADIR=${DATADIR}

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	do-configure
SUBST_FILES.sysconf=	man/dbmail-imapd.8 man/dbmail-lmtpd.8 man/dbmail-pop3d.8
SUBST_FILES.sysconf+=	man/dbmail-smtp.1 man/dbmail-users.8 man/dbmail-util.8
SUBST_FILES.sysconf+=	man/dbmail.1 man/dbmail.conf.5 man/dbmail-export.8
SUBST_FILES.sysconf+=	man/dbmail-sievecmd.8 mail/dbmail-timsieved.8
SUBST_SED.sysconf=	-e 's|/etc/dbmail\.conf|${PKG_SYSCONFDIR}/dbmail.conf|g'
SUBST_MESSAGE.sysconf=	Fixing sysconf paths.

INSTALLATION_DIRS=	lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin ${DOCSDIR} ${EGDIR} ${DATADIR}/sql

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${DESTDIR}${EGDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCSDIR}
.endfor

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gmime+=	gmime>=2.2.10
.include "../../mail/gmime/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
