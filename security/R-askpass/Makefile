# $NetBSD: Makefile,v 1.1 2019/08/09 19:02:20 brook Exp $

R_PKGNAME=	askpass
R_PKGVER=	1.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Safe password entry for R, Git, and SSH
LICENSE=	mit

DEPENDS+=	R-sys>=2.1:../../sysutils/R-sys

USE_LANGUAGES=	c

REPLACE_INTERPRETER+=		osascript
REPLACE.osascript.old=		[^[:space:]]*env osascript
REPLACE.osascript.new=		/usr/bin/osascript
REPLACE_FILES.osascript=	inst/mac-askpass inst/mac-simplepass

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
