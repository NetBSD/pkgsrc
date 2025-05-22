# $NetBSD: Makefile,v 1.1 2025/05/22 20:54:15 nia Exp $

DISTNAME=	clearlooks-phenix-7.1
PKGNAME=	${DISTNAME:S/-phenix/-phenix-theme/1}
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpfleury/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpfleury/clearlooks-phenix
COMMENT=	GTK 3 port of Clearlooks theme
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pax
USE_LANGUAGES=	# none
NO_BUILD=	yes

DEPENDS+=	gtk2-engines-[0-9]*:../../x11/gtk2-engines
DEPENDS+=	gnome-themes-standard-[0-9]*:../../graphics/gnome-themes-standard

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS+=	share/themes/Clearlooks-Phenix

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp index.theme \
	    gtk-2.0 gtk-3.0 metacity-1 openbox-3 xfwm4 \
	    ${DESTDIR}${PREFIX}/share/themes/Clearlooks-Phenix

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
