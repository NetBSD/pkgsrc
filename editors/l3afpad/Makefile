# $NetBSD: Makefile,v 1.29 2026/11/17 12:10:36 wiz Exp $

DISTNAME=	l3afpad-0.8.18.1.11
PKGREVISION=	27
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevenhoneyman/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stevenhoneyman/l3afpad
COMMENT=	Simple text editor forked from Leafpad, supports GTK+ 3.x
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

USE_TOOLS+=	automake aclocal autoheader automake autoconf
USE_TOOLS+=	intltool msgfmt msgmerge xgettext perl
USE_TOOLS+=	gmake pkg-config

GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} autoreconf -fiv

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
