# $NetBSD: Makefile,v 1.84.2.1 2006/01/15 15:04:48 salo Exp $
#

DISTNAME=		sudo-1.6.8p12
PKGNAME=		sudo-1.6.8pl12
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.courtesan.com/sudo/dist/ \
			ftp://ftp.courtesan.com/pub/sudo/ \
			ftp://ftp.cs.colorado.edu/pub/sudo/ \
			ftp://ftp.uu.net/pub/security/sudo/ \
			ftp://ftp.tux.org/pub/security/sudo/ \
			http://www.courtesan.com/sudo/dist/beta/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.courtesan.com/sudo/
COMMENT=		Allow others to run commands as root

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-root-mailer
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "options.mk"

CONFIGURE_ARGS+=	--with-nbsdops --disable-path-info

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES_PERMS=	${EGDIR}/sudoers ${PKG_SYSCONFDIR}/sudoers 0 0 0440

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoers ${EGDIR}/sudoers
	${INSTALL_DATA} ${WRKSRC}/README* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
