# $NetBSD: Makefile,v 1.6 2022/12/06 21:33:03 vins Exp $

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

INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/themes ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
.for i in config.example.ini config/*.tmpl
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${EGDIR}
.endfor
.for t in themes/*
	${INSTALL_DATA} ${WRKSRC}/config/${t} 			\
		${DESTDIR}${EGDIR}/themes
.endfor

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
