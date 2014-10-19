# $NetBSD: Makefile,v 1.5 2014/10/19 22:27:44 alnsn Exp $
#

ENGINE=		posix
ENGINE_DIR=	posix

.include "../../devel/lua-lrexlib/Makefile.common"
PKGREVISION=	3

COMMENT=	POSIX regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
