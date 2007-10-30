# $NetBSD: Makefile,v 1.14 2007/10/30 22:52:42 shannonjr Exp $
#

DISTNAME=		dbmail-2.2.7
CATEGORIES=		mail
MASTER_SITES=		http://www.dbmail.org/download/2.2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.dbmail.org/
COMMENT=		Store and retrieve mail messages in a database

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-${SQLDB}
CONFIGURE_ARGS+=	--with-pkglibdir=${PREFIX}/lib/dbmail
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

EGDIR=			${PREFIX}/share/examples/dbmail
CONF_FILES=		${EGDIR}/dbmail.conf ${PKG_SYSCONFDIR}/dbmail.conf
RCD_SCRIPTS=		dbmail dbmailimapd dbmaillmtpd dbmailpop3d dbmail-timsieved

PLIST_SUBST+=		SQLDB=${SQLDB:Q}

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	do-configure
SUBST_FILES.sysconf=	man/dbmail-imapd.8 man/dbmail-lmtpd.8 man/dbmail-pop3d.8
SUBST_FILES.sysconf+=	man/dbmail-smtp.1 man/dbmail-users.8 man/dbmail-util.8
SUBST_FILES.sysconf+=	dbmail.h
SUBST_SED.sysconf=	-e 's|/etc/dbmail\.conf|${PKG_SYSCONFDIR}/dbmail.conf|g'
SUBST_MESSAGE.sysconf=	Fixing sysconf paths.

INSTALLATION_DIRS=	lib man ${PKGMANDIR}/man1 ${PKGMANDIR}/man8 sbin share/examples/dbmail

post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sql/mysql/migrate_from_2.0_to_2.2.mysql ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sql/postgresql/migrate_from_2.0_to_2.2.pgsql ${EGDIR}


.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
