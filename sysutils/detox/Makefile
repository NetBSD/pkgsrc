# $NetBSD: Makefile,v 1.14 2026/02/15 13:59:47 wiz Exp $

DISTNAME=		detox-3.0.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=dharple/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://github.com/dharple/detox
COMMENT=		Removes non-standard characters from filenames
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
USE_TOOLS+=		lex:run

EGDIR=			${PREFIX}/share/examples/detox
INSTALLATION_DIRS+=	share/examples/detox
CONF_FILES=		${EGDIR}/detoxrc ${PKG_SYSCONFDIR}/detoxrc

post-install:
	mv ${DESTDIR}${PREFIX}/etc/detoxrc* ${DESTDIR}${PREFIX}/share/examples/detox

.include "../../mk/bsd.pkg.mk"
