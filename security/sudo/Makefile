# $NetBSD: Makefile,v 1.75 2004/11/30 00:27:10 xtraeme Exp $
#

DISTNAME=		sudo-1.6.8p5
PKGNAME=		sudo-1.6.8pl5
PKGREVISION=		#
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

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-root-mailer --disable-setreuid
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-skey
.elif ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--without-skey
.endif

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
