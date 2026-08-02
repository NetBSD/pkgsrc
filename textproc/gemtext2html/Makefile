# $NetBSD: Makefile,v 1.4 2026/08/02 20:26:26 js Exp $

PKGNAME=	gemtext2html-1.2
DISTNAME=	v${PKGVERSION_NOREV}
CATEGORIES=	textproc
MASTER_SITES=	https://git.nil.im/js/Gemtext2HTML/archive/
DIST_SUBDIR=	gemtext2html

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	gemini://nil.im/gemtext2html
COMMENT=	Simple library and command line utility to translate Gemtext to HTML
LICENSE=	gnu-lgpl-v3

WRKSRC=			${WRKDIR}/gemtext2html
GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw
USE_TOOLS+=		autoconf automake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=		clang>=3.2:../../lang/clang
.endif

PLIST_SRC=		PLIST
.if ${OPSYS} == "Darwin"
PLIST_SRC+=		PLIST.framework
.endif

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/objfw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
