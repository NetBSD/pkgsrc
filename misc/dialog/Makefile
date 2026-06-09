# $NetBSD: Makefile,v 1.96 2026/06/09 18:07:17 wiz Exp $

DISTNAME=	dialog-1.3-20260107
PKGNAME=	${DISTNAME:C/-2/.2/}
CATEGORIES=	misc
MASTER_SITES=	https://invisible-island.net/archives/dialog/ \
		https://invisible-mirror.net/archives/dialog/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invisible-island.net/dialog/dialog.html
COMMENT=	Display dialog boxes from shell scripts
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
MAKE_FILE=		makefile
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-libtool

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 060000
CONFIGURE_ARGS+=	--disable-widec
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
