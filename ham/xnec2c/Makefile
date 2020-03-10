# $NetBSD: Makefile,v 1.24 2020/03/10 22:10:17 wiz Exp $

DISTNAME=	xnec2c-3.5.1
PKGREVISION=	9
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/5b4az/pkg/nec2/xnec2c/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qsl.net/5b4az/pages/nec2.html
COMMENT=	GTK+ graphical interactive version of nec2c
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	intltool msgfmt pax pkg-config

INSTALLATION_DIRS=	share/doc/xnec2c

post-install:
	cd ${WRKSRC}/doc && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/share/doc/xnec2c

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
