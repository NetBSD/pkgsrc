# $NetBSD: Makefile,v 1.6 2018/03/22 08:14:52 adam Exp $
#

ENGINE=		onig
ENGINE_DIR=	oniguruma

.include "../../devel/lua-lrexlib/Makefile.common"
PKGREVISION=	4

COMMENT=	Oniguruma regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lonig

.include "../../lang/lua/module.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
