# $NetBSD: Makefile,v 1.5 2014/05/05 00:48:02 ryoon Exp $

DISTNAME=	xnec2c-2.3-beta
PKGNAME=	${DISTNAME:S/-beta/beta/}
PKGREVISION=	3
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/5b4az/pkg/nec2/xnec2c/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qsl.net/5b4az/pages/nec2.html
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
