# $NetBSD: Makefile,v 1.15 2007/11/03 11:39:49 obache Exp $
#

DISTNAME=		dbmail-2.2.7
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://www.dbmail.org/download/2.2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.dbmail.org/
COMMENT=		Store and retrieve mail messages in a database

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-logdir=${VARBASE:Q}/log
CONFIGURE_ARGS+=	--with-pkglibdir=${PREFIX:Q}/lib/dbmail
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}/run
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

EGDIR=			${PREFIX}/share/examples/dbmail
CONF_FILES=		${EGDIR}/dbmail.conf ${PKG_SYSCONFDIR}/dbmail.conf
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
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${EGDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../mail/gmime/buildlink3.mk"
BUILDLINK_API_DEPENDS.gmime+=	gmime>=2.1.19
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
