# $NetBSD: Makefile,v 1.9 2022/08/11 05:08:16 gutteridge Exp $

DISTNAME=	l3afpad-0.8.18.1.11
PKGREVISION=	8
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevenhoneyman/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stevenhoneyman/l3afpad
COMMENT=	Simple text editor forked from Leafpad, supports GTK+ 3.x
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	automake aclocal autoheader automake autoconf
USE_TOOLS+=	intltool msgfmt msgmerge xgettext perl
USE_TOOLS+=	gmake pkg-config

GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
