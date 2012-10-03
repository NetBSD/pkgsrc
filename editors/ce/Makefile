# $NetBSD: Makefile,v 1.19 2012/10/03 11:43:31 asau Exp $
#

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "Makefile.common"

COMMENT+=		, tty version


REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	teach-ce.in

BUILD_TARGET=		ce
INSTALL_TARGET=		install man-install

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
