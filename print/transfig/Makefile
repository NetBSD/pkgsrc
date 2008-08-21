# $NetBSD: Makefile,v 1.35.4.1 2008/08/21 11:35:30 rtr Exp $

DISTNAME=	transfig.3.2.5
PKGNAME=	transfig-3.2.5
PKGREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	ftp://epb.lbl.gov/xfig/alpha/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xfig.org/
COMMENT=	TeX document creation tool utilizing portable graphics

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=		yes

.include "../../mk/bsd.prefs.mk"

# A default paper size is used only in the IBM-GL/HP-GL driver:
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
MAKE_ENV+=		DDA4="-DA4"
.endif

# We must use GNU make on Linux
.if ${OPSYS} == "Linux"
USE_TOOLS+=		gmake
.endif

MAKE_ENV+=		ICONVLIBS="${BUILDLINK_LDADD.iconv}"

# fig2ps2tex needs csh which might not be present on eg. Linux
CHECK_INTERPRETER_SKIP=	bin/fig2ps2tex

.include "../../graphics/png/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
