# $NetBSD: Makefile,v 1.18 2003/08/01 14:22:18 drochner Exp $

DISTNAME=		sqlite-2.8.5
WRKSRC=			${WRKDIR}/sqlite-build
CATEGORIES=		databases
MASTER_SITES=		http://www.hwaci.com/sw/sqlite/ \
			http://www.sqlite.org/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.hwaci.com/sw/sqlite/
COMMENT=		SQL Database Engine In A C Library

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../sqlite/configure
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ENV+=		config_TARGET_READLINE_INC="-I${BUILDLINK_PREFIX.readline}/include"

CFLAGS+=		-DUINT32_TYPE=u_int32_t -DUINT16_TYPE=u_int16_t \
			-DUINT8_TYPE=u_int8_t -DINTPTR_TYPE=long

PKGCONFIG_OVERRIDE=	${WRKDIR}/sqlite/sqlite.pc.in

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
