# $NetBSD: Makefile,v 1.12 2002/10/25 18:32:43 wiz Exp $

DISTNAME=		sqlite-2.2.5
CATEGORIES=		databases
MASTER_SITES=		http://www.hwaci.com/sw/sqlite/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.hwaci.com/sw/sqlite/
COMMENT=		SQL Database Engine In A C Library

WRKSRC=			${WRKDIR}/sqlite-build

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../sqlite/configure
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ENV+=		config_TARGET_READLINE_INC="-I${BUILDLINK_PREFIX.readline}/include"

CFLAGS+=		-DUINT32_TYPE=u_int32_t -DUINT16_TYPE=u_int16_t \
			-DUINT8_TYPE=u_int8_t -DINTPTR_TYPE=long

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
