# $NetBSD: Makefile,v 1.5 2014/10/19 22:27:44 alnsn Exp $
#

ENGINE=		onig
ENGINE_DIR=	oniguruma

.include "../../devel/lua-lrexlib/Makefile.common"
PKGREVISION=	3

COMMENT=	Oniguruma regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lonig

.include "../../lang/lua/module.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
