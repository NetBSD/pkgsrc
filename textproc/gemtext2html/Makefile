# $NetBSD: Makefile,v 1.1 2026/06/18 22:03:18 js Exp $

PKGNAME=	gemtext2html-0.1
DISTNAME=	v${PKGVERSION_NOREV}
CATEGORIES=	textproc
MASTER_SITES=	https://git.nil.im/js/Gemtext2HTML/archive/
DIST_SUBDIR=	gemtext2html

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	gemini://nil.im/gemtext2html
COMMENT=	Simple library and command line utility to translate Gemtext to HTML
LICENSE=	gnu-lgpl-v3

WRKSRC=			${WRKDIR}/gemtext2html
USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=		clang>=3.2:../../lang/clang
.endif

.include "../../devel/objfw/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
