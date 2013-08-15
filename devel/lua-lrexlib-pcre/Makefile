# $NetBSD: Makefile,v 1.4 2013/08/15 06:32:05 obache Exp $
#

ENGINE=		pcre
ENGINE_DIR=	pcre

.include "../../devel/lua-lrexlib/Makefile.common"
PKGREVISION=2

COMMENT=	PCRE regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lpcre

.include "../../lang/lua/module.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
