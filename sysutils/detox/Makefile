# $NetBSD: Makefile,v 1.13 2021/03/06 18:26:07 wiz Exp $

DISTNAME=		detox-1.4.2
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
