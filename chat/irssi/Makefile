# $NetBSD: Makefile,v 1.115 2026/09/02 19:01:07 wiz Exp $

DISTNAME=		irssi-1.4.5
PKGREVISION=		6
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=irssi/}
GITHUB_RELEASE=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.irssi.org/
COMMENT=		Secure and modular IRC client with text mode user interface
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pkg-config
TEST_TARGET=		check

MESON_ARGS+=		-Dwith-proxy=yes

EGDIR=			${PREFIX}/share/examples/irssi
INSTALLATION_DIRS+=	${EGDIR}
CONF_FILES=		${EGDIR}/irssi.conf ${PKG_SYSCONFDIR}/irssi.conf

OPSYSVARS+=		MODULEEXT
MODULEEXT.Darwin=	bundle
MODULEEXT.*=		so
PLIST_SUBST+=		MODULEEXT=${MODULEEXT}

post-install:
	${INSTALL_DATA} ${WRKSRC}/irssi.conf ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
