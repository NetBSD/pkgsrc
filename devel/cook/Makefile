# $NetBSD: Makefile,v 1.26 2014/05/29 23:35:34 wiz Exp $

DISTNAME=	cook-2.26
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://miller.emu.id.au/pmiller/software/cook/

MAINTAINER=	groo@NetBSD.org
HOMEPAGE=	http://miller.emu.id.au/pmiller/software/cook/
COMMENT=	More powerful replacement for the traditional make(1) tool

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
