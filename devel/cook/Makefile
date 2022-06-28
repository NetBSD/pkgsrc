# $NetBSD: Makefile,v 1.35 2022/06/28 11:31:41 wiz Exp $

DISTNAME=	cook-2.26
PKGREVISION=	12
CATEGORIES=	devel
#MASTER_SITES=	http://miller.emu.id.au/pmiller/software/cook/

MAINTAINER=	groo@NetBSD.org
#HOMEPAGE=	http://miller.emu.id.au/pmiller/software/cook/
COMMENT=	More powerful replacement for the traditional make(1) tool

USE_TOOLS+=	groff msgfmt yacc perl:run
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
