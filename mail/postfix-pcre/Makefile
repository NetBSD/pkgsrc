# $NetBSD: Makefile,v 1.3 2015/10/05 00:14:13 taca Exp $
#

PKGREVISION=		1
COMMENT=		Postfix SMTP server PCRE map module

POSTFIX_LIB=		pcre
POSTFIX_LIBDIR=		src/util
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.pcre}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.pcre}/lib -lpcre			\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre}/lib

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
