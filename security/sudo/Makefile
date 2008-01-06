# $NetBSD: Makefile,v 1.106 2008/01/06 16:08:24 taca Exp $
#

DISTNAME=		sudo-1.6.9p11
CATEGORIES=		security
MASTER_SITES=		http://www.courtesan.com/sudo/dist/ \
			ftp://ftp.courtesan.com/pub/sudo/ \
			ftp://ftp.uwsg.indiana.edu/pub/security/sudo/ \
			ftp://ftp.twaren.net/Unix/Security/Sudo/ \
			http://ftp.tux.org/pub/security/sudo/ \
			http://netmirror.org/mirror/ftp.sudo.ws/ \
			http://www.courtesan.com/sudo/dist/OLD/ \
			http://www.courtesan.com/sudo/dist/beta/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.courtesan.com/sudo/
COMMENT=		Allow others to run commands as root

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
OWN_DIRS+=		${VARBASE}/run
GNU_CONFIGURE=		yes
BUILD_DEFS+=		VARBASE
PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

# to always install man instead of cat
CONFIGURE_ENV+=		NROFFPROG=${CAT:Q}
CONFIGURE_ENV+=		mansectsu=8
CONFIGURE_ENV+=		mansectform=5
CONFIGURE_ARGS+=	--disable-root-mailer
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-timedir=${VARBASE:Q}/run/sudo
CONFIGURE_ARGS+=	--with-logpath=${VARBASE:Q}/log/sudo.log

.include "options.mk"

CONFIGURE_ARGS+=	--with-nbsdops --disable-path-info

DOCDIR=			share/doc/${PKGBASE}
EGDIR=			share/examples/${PKGBASE}
CONF_FILES_PERMS=	${EGDIR}/sudoers ${PKG_SYSCONFDIR}/sudoers 0 0 0440
SPECIAL_PERMS+=		bin/sudo ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoers ${DESTDIR}${PREFIX}/${EGDIR}/sudoers
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
