# $NetBSD: Makefile,v 1.8 2022/12/30 03:26:29 sjmulder Exp $

DISTNAME=	tut-1.0.31
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
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/man7

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
.for i in config.example.ini config/*.tmpl
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${EGDIR}
.endfor
.for t in themes/*
	${INSTALL_DATA} ${WRKSRC}/config/${t}			\
		${DESTDIR}${EGDIR}/themes
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/man/tut.1	 	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/docs/man/tut.5		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_DATA} ${WRKSRC}/docs/man/tut.7		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
