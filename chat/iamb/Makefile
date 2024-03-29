# $NetBSD: Makefile,v 1.4 2024/03/29 20:43:19 pin Exp $

DISTNAME=	iamb-0.0.9
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ulyssa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://iamb.chat/
COMMENT=	Matrix client for Vim addicts
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5 \
			share/examples/iamb share/icons/hicolor/scalable/apps \
			share/applications

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/iamb.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/iamb.1
	${INSTALL_MAN} ${WRKSRC}/docs/iamb.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/iamb.5
	${INSTALL_DATA} ${WRKSRC}/config.example.toml \
		${DESTDIR}${PREFIX}/share/examples/iamb
	${INSTALL_DATA} ${WRKSRC}/docs/iamb.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/iamb.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../lang/rust/cargo.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
