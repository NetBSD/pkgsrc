# $NetBSD: Makefile,v 1.23 2004/04/24 22:46:09 jlam Exp $

DISTNAME=		sqlite-2.8.13
CATEGORIES=		databases
MASTER_SITES=		http://www.hwaci.com/sw/sqlite/ \
			http://www.sqlite.org/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.hwaci.com/sw/sqlite/
COMMENT=		SQL Database Engine in a C Library

WRKSRC=			${WRKDIR}/sqlite-build
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../sqlite/configure
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ENV+=		config_TARGET_READLINE_INC="-I${BUILDLINK_PREFIX.readline}/include"

CFLAGS+=		-DUINT32_TYPE=u_int32_t -DUINT16_TYPE=u_int16_t \
			-DUINT8_TYPE=u_int8_t -DINTPTR_TYPE=long

PKGCONFIG_OVERRIDE=	${WRKDIR}/sqlite/sqlite.pc.in

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
