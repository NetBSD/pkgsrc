# $NetBSD: Makefile,v 1.5 2022/11/30 13:34:02 sjmulder Exp $

DISTNAME=	tut-1.0.24
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=RasmusLindroth/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://tut.anv.nu/
COMMENT=	TUI for Mastodon with shellout
LICENSE=	mit

EGDIR=		${PREFIX}/share/examples/tut
DOCDIR=		${PREFIX}/share/doc/tut

INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
.for i in config.example.ini config/toot.tmpl config/user.tmpl
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${EGDIR}
.endfor

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
