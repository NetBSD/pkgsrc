# $NetBSD: Makefile,v 1.2 2005/01/09 04:17:39 schmonz Exp $
#

DISTNAME=		dbmail-2.0.1
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://www.dbmail.org/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.dbmail.org/
COMMENT=		Store and retrieve mail messages in a database

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

EGDIR=			${PREFIX}/share/examples/dbmail
CONF_FILES=		${EGDIR}/dbmail.conf ${PKG_SYSCONFDIR}/dbmail.conf
RCD_SCRIPTS=		dbmail dbmailimapd dbmaillmtpd dbmailpop3d

PLIST_SUBST+=		SQLDB=${SQLDB}

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	do-configure
SUBST_FILES.sysconf=	man/dbmail-imapd.8 man/dbmail-lmtpd.8 man/dbmail-pop3d.8
SUBST_FILES.sysconf+=	man/dbmail-smtp.1 man/dbmail-users.8 man/dbmail-util.8
SUBST_FILES.sysconf+=	dbmail.h
SUBST_SED.sysconf=	-e 's|/etc/dbmail\.conf|${PKG_SYSCONFDIR}/dbmail.conf|g'
SUBST_MESSAGE.sysconf=	"Fixing sysconf paths."

INSTALLATION_DIRS=	lib man man/man1 man/man8 sbin share/examples/dbmail
post-install:
	${INSTALL_DATA} ${WRKSRC}/dbmail.conf ${EGDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
