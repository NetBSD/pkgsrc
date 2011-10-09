# $NetBSD: Makefile,v 1.2 2011/10/09 10:02:47 cheusov Exp $
#

ENGINE=		pcre
ENGINE_DIR=	pcre

.include "../../devel/lua-lrexlib/Makefile.common"

COMMENT=	PCRE regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lpcre

.include "../../lang/lua/module.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
