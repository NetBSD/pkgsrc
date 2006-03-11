# $NetBSD: Makefile,v 1.16 2006/03/11 10:07:49 ghen Exp $
#

.include "Makefile.common"

COMMENT+=		, tty version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	teach-ce.in

BUILD_TARGET=		ce
INSTALL_TARGET=		install man-install

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
