# $NetBSD: Makefile,v 1.44 2014/02/24 12:12:02 wiz Exp $

DISTNAME=	transfig.3.2.5e
PKGNAME=	${DISTNAME:S/g./g-/}
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xfig.org/
COMMENT=	TeX document creation tool utilizing portable graphics

USE_IMAKE=		yes

.include "../../mk/bsd.prefs.mk"

# A default paper size is used only in the IBM-GL/HP-GL driver:
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
MAKE_ENV+=		DDA4="-DA4"
.endif

MAKE_ENV+=		ICONVLIBS="${BUILDLINK_LDADD.iconv}"

# fig2ps2tex needs csh which might not be present on eg. Linux
CHECK_INTERPRETER_SKIP=	bin/fig2ps2tex

.include "../../graphics/png/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
