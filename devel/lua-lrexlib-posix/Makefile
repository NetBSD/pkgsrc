# $NetBSD: Makefile,v 1.3 2013/08/15 06:32:06 obache Exp $
#

ENGINE=		posix
ENGINE_DIR=	posix

.include "../../devel/lua-lrexlib/Makefile.common"
PKGREVISION=	1

COMMENT=	POSIX regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
