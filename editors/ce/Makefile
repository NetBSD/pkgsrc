# $NetBSD: Makefile,v 1.20 2013/10/09 08:55:44 roy Exp $
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

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
