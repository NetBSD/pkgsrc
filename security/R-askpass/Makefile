# $NetBSD: Makefile,v 1.3 2025/01/11 11:39:34 mef Exp $

R_PKGNAME=	askpass
R_PKGVER=	1.2.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Safe password entry for R, Git, and SSH
LICENSE=	mit

DEPENDS+=	R-sys>=2.1:../../sysutils/R-sys

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

REPLACE_INTERPRETER+=		osascript
REPLACE.osascript.old=		[^[:space:]]*env osascript
REPLACE.osascript.new=		/usr/bin/osascript
REPLACE_FILES.osascript=	inst/mac-askpass inst/mac-simplepass

CHECK_INTERPRETER_SKIP+=	lib/R/library/askpass/mac-askpass
CHECK_INTERPRETER_SKIP+=	lib/R/library/askpass/mac-simplepass

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
