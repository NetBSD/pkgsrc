# $NetBSD: Makefile,v 1.4 2001/06/28 06:00:53 jlam Exp $
#

PKGNAME=	prc-tools-gdb-${PRC_TOOLS_VERS}
COMMENT=	gdb for GNU tool chain for Palm cross development

BASE_DIST=	gdb
BASE_VERS=	4.18

.include "../../devel/prc-tools/Makefile.common"

USE_BUILDLINK_ONLY=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb/gdb ${PREFIX}/bin/m68k-palmos-gdb
	${INSTALL_MAN} ${WRKSRC}/gdb/gdb/gdb.1 \
		${PREFIX}/man/man1/m68k-palmos-gdb.1

.include "../../mk/bsd.pkg.mk"
