# $NetBSD: Makefile,v 1.3 2013/08/15 06:32:05 obache Exp $
#

ENGINE=		onig
ENGINE_DIR=	oniguruma

.include "../../devel/lua-lrexlib/Makefile.common"
PKGREVISION=	1

COMMENT=	Oniguruma regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lonig

.include "../../lang/lua/module.mk"
.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
