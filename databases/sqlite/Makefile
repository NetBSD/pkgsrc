# $NetBSD: Makefile,v 1.5 2001/12/15 22:18:41 reinoud Exp $

DISTNAME=		sqlite-2.1.7
CATEGORIES=		databases
MASTER_SITES=		http://www.hwaci.com/sw/sqlite/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.hwaci.com/sw/sqlite/
COMMENT=		SQL Database Engine In A C Library

WRKSRC=			${WRKDIR}/sqlite-build

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../sqlite/configure
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ENV+=		config_TARGET_READLINE_INC="-I${BUILDLINK_DIR}/include"

CFLAGS+=		-DUINT32_TYPE=uint32_t -DUINT16_TYPE=uint16_t \
			-DUINT8_TYPE=uint8_t -DINTPTR_TYPE=long 

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
