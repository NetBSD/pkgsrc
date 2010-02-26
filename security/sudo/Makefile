# $NetBSD: Makefile,v 1.119 2010/02/26 01:08:38 taca Exp $
#

DISTNAME=		sudo-1.7.2p4
CATEGORIES=		security
MASTER_SITES=		http://www.courtesan.com/sudo/dist/ \
			ftp://ftp.courtesan.com/pub/sudo/ \
			ftp://ftp.uwsg.indiana.edu/pub/security/sudo/ \
			ftp://ftp.twaren.net/Unix/Security/Sudo/ \
			http://ftp.tux.org/pub/security/sudo/

DIST_SUBDIR=		${DISTNAME}-200805130

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.courtesan.com/sudo/
COMMENT=		Allow others to run commands as root
LICENSE=		modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
OWN_DIRS+=		${VARBASE}/run
GNU_CONFIGURE=		yes
BUILD_DEFS+=		VARBASE
PKG_DESTDIR_SUPPORT=	destdir
PLIST_VARS+=		ldap

.include "../../mk/bsd.prefs.mk"

# to always install man instead of cat
CONFIGURE_ENV+=		NROFFPROG=${CAT:Q}
CONFIGURE_ENV+=		mansectsu=8
CONFIGURE_ENV+=		mansectform=5
CONFIGURE_ARGS+=	--disable-root-mailer --with-ignore-dot
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-timedir=${VARBASE}/run/sudo
CONFIGURE_ARGS+=	--with-logpath=${VARBASE}/log/sudo.log

.include "options.mk"

CONFIGURE_ARGS+=	--with-nbsdops --disable-path-info

DOCDIR=			share/doc/${PKGBASE}
EGDIR=			share/examples/${PKGBASE}
CONF_FILES_PERMS=	${EGDIR}/sudoers ${PKG_SYSCONFDIR}/sudoers \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0440
SPECIAL_PERMS+=		bin/sudo ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoers ${DESTDIR}${PREFIX}/${EGDIR}/sudoers
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
