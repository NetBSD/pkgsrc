# $NetBSD: Makefile,v 1.1.1.1 2011/07/24 08:50:40 cheusov Exp $
#

ENGINE=		onig
ENGINE_DIR=	oniguruma

.include "../../devel/lua-lrexlib/Makefile.common"

COMMENT=	Oniguruma regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@tut.by

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lonig

.include "../../lang/lua/module.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
