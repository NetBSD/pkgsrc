# $NetBSD: Makefile,v 1.2 2011/10/09 10:02:47 cheusov Exp $
#

ENGINE=		onig
ENGINE_DIR=	oniguruma

.include "../../devel/lua-lrexlib/Makefile.common"

COMMENT=	Oniguruma regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lonig

.include "../../lang/lua/module.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
