# $NetBSD: Makefile,v 1.3 2012/03/03 00:12:56 wiz Exp $
#

ENGINE=		pcre
ENGINE_DIR=	pcre

.include "../../devel/lua-lrexlib/Makefile.common"
PKGREVISION=1

COMMENT=	PCRE regexp library for Lua (lrexlib project)
MAINTAINER=	cheusov@NetBSD.org

DESCR_SRC+=	${.CURDIR}/DESCR

LDFLAGS+=	-lpcre

.include "../../lang/lua/module.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
