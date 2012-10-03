# $NetBSD: Makefile,v 1.23 2012/10/03 21:54:28 wiz Exp $

DISTNAME=	cook-2.26
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://miller.emu.id.au/pmiller/software/cook/

MAINTAINER=	groo@NetBSD.org
HOMEPAGE=	http://miller.emu.id.au/pmiller/software/cook/
COMMENT=	More powerful replacement for the traditional make(1) tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt yacc perl:run
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

LIBS.SunOS+=	-lintl

INSTALLATION_DIRS=	${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			datadir=${DESTDIR}${PREFIX}/share/cook \
			libdir=${DESTDIR}${PREFIX}/lib/cook \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
