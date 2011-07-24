# $NetBSD: Makefile,v 1.1.1.1 2011/07/24 08:49:29 cheusov Exp $
#

ENGINE=		pcre
ENGINE_DIR=	pcre

.include "../../devel/lua-lrexlib/Makefile.common"

COMMENT=	PCRE regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@tut.by

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lpcre

.include "../../lang/lua/module.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
