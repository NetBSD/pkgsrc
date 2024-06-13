# $NetBSD: Makefile,v 1.23 2024/06/13 13:46:55 bsiegert Exp $

DISTNAME=	ymuse-0.22
PKGREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=yktoo/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yktoo/ymuse/
COMMENT=	GTK client for Music Player Daemon (MPD) written in Go
LICENSE=	apache-2.0

USE_TOOLS+=		bash msgfmt pax pkg-config

INSTALLATION_DIRS+=	share/icons ${PKGLOCALEDIR}/locale

REPLACE_BASH+=		resources/scripts/generate-mos

pre-build:
	cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} generate

post-install:
	cd ${WRKSRC}/resources/icons/ && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/icons
	cd ${WRKSRC}/resources/i18n/generated/ && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
