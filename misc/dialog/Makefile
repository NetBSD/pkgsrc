# $NetBSD: Makefile,v 1.65 2014/02/03 16:42:32 wiz Exp $

DISTNAME=	dialog-1.2-20140112
PKGNAME=	${DISTNAME:C/-2/.2/}
CATEGORIES=	misc
MASTER_SITES=	ftp://invisible-island.net/dialog/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://invisible-island.net/dialog/dialog.html
COMMENT=	Display dialog boxes from shell scripts
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
MAKE_FILE=	makefile
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-libtool

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-P]-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath=	dialog-config.in
SUBST_MESSAGE.rpath=	Fixing rpath in dialog-config
SUBST_SED.rpath=	-e 's;-L\(.\);${_COMPILER_RPATH_FLAG}\1\{exec_prefix\}/lib -L\1;'
SUBST_STAGE.rpath=	pre-configure

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
