# $NetBSD: Makefile,v 1.98 2007/10/10 00:08:24 taca Exp $
#

DISTNAME=		sudo-1.6.9p6
CATEGORIES=		security
MASTER_SITES=		http://www.courtesan.com/sudo/dist/ \
			ftp://ftp.courtesan.com/pub/sudo/ \
			ftp://ftp.cs.colorado.edu/pub/sudo/ \
			ftp://ftp.uu.net/pub/security/sudo/ \
			ftp://ftp.tux.org/pub/security/sudo/ \
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

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES_PERMS=	${EGDIR}/sudoers ${PKG_SYSCONFDIR}/sudoers 0 0 0440
SPECIAL_PERMS+=		bin/sudo ${SETUID_ROOT_PERMS}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoers ${EGDIR}/sudoers
	${INSTALL_DATA} ${WRKSRC}/README* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
