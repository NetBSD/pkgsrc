# $NetBSD: Makefile,v 1.4 2020/03/24 18:03:05 nia Exp $

DISTNAME=	materia-gtk-theme-20200320
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nana-4/}
GITHUB_PROJECT=	materia-theme
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/nana-4/materia-theme
COMMENT=	Material Design theme for GTK based desktop environments
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	bash
NO_BUILD=	yes

REPLACE_BASH+=	install.sh

DEPENDS+=	gnome-themes-standard-[0-9]*:../../graphics/gnome-themes-standard
DEPENDS+=	gtk2-engines-murrine-[0-9]*:../../x11/gtk2-engines-murrine

do-install:
	cd ${WRKSRC} && ${BASH} ./install.sh -d ${DESTDIR}${PREFIX}/share/themes

.include "../../mk/bsd.pkg.mk"
