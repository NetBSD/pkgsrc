# $NetBSD: Makefile,v 1.134.2.1 2012/05/19 10:42:02 tron Exp $
#

DISTNAME=		sudo-1.7.9p1
CATEGORIES=		security
MASTER_SITES=		http://www.sudo.ws/dist/ \
			ftp://ftp.sudo.ws/pub/sudo/ \
			ftp://ftp.uwsg.indiana.edu/pub/security/sudo/ \
			ftp://ftp.twaren.net/Unix/Security/Sudo/ \
			http://ftp.tux.org/pub/security/sudo/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.sudo.ws/
COMMENT=		Allow others to run commands as root
LICENSE=		isc AND modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
OWN_DIRS+=		${VARBASE}/run
GNU_CONFIGURE=		yes
BUILD_DEFS+=		VARBASE
PKG_DESTDIR_SUPPORT=	user-destdir
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
OWN_DIRS+=		${PKG_SYSCONFDIR}/sudoers.d
SPECIAL_PERMS+=		bin/sudo ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		bin/sudoreplay ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 511

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoers ${DESTDIR}${PREFIX}/${EGDIR}/sudoers
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
