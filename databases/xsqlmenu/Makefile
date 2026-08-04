# $NetBSD: Makefile,v 1.40 2026/08/04 20:28:49 wiz Exp $

DISTNAME=	xsqlmenu-2.10
PKGREVISION=	20
CATEGORIES=	databases
MASTER_SITES=	https://www.jlab.org/~saw/xsqlmenu/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://userweb.jlab.org/~saw/xsqlmenu/
COMMENT=	X based GUI for MySQL
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
MAKE_ENV+=	MAKE=${MAKE_PROGRAM:Q}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsqlmenu ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.README \
		${DESTDIR}${PREFIX}/share/doc/xsqlmenu
	${INSTALL_DATA} ${WRKSRC}/xsqlmenu.lsm \
		${DESTDIR}${PREFIX}/share/doc/xsqlmenu
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS CHANGES COPYING TODO \
		${DESTDIR}${PREFIX}/share/doc/xsqlmenu

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
