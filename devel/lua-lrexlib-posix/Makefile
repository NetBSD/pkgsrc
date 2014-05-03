# $NetBSD: Makefile,v 1.4 2014/05/03 13:14:37 alnsn Exp $
#

ENGINE=		posix
ENGINE_DIR=	posix

.include "../../devel/lua-lrexlib/Makefile.common"
PKGREVISION=	2

COMMENT=	POSIX regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
