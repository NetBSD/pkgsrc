# $NetBSD: Makefile,v 1.23 2024/01/10 19:14:36 bsiegert Exp $

DISTNAME=	tut-2.0.1
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=RasmusLindroth/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://tut.anv.nu/
COMMENT=	TUI for Mastodon with shellout
LICENSE=	mit

EGS=	config.example.toml config/toot.tmpl config/user.tmpl
EGDIR=	share/examples/${PKGBASE}
DOCDIR=	share/doc/${PKGBASE}


INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/themes ${DOCDIR}
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/man7

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md			\
		${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${EGS:S|^|${WRKSRC}/|}			\
		${DESTDIR}${PREFIX}/${EGDIR}
.for t in *.toml
	${INSTALL_DATA} ${WRKSRC}/config/themes/${t}		\
		${DESTDIR}${PREFIX}/${EGDIR}/themes
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
