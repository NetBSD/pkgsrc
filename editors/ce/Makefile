# $NetBSD: Makefile,v 1.17 2007/01/07 09:13:52 rillig Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
