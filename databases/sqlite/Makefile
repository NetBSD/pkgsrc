# $NetBSD: Makefile,v 1.33 2005/12/02 21:46:50 joerg Exp $

DISTNAME=		sqlite-2.8.16
CATEGORIES=		databases
MASTER_SITES=		http://www.hwaci.com/sw/sqlite/ \
			http://www.sqlite.org/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.hwaci.com/sw/sqlite/
COMMENT=		SQL Database Engine in a C Library

WRKSRC=			${WRKDIR}/sqlite-build
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../sqlite-2.8.16/configure
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ENV+=		config_TARGET_READLINE_INC="-I${BUILDLINK_PREFIX.readline}/include"
CONFIG_GUESS_OVERRIDE=	../sqlite-2.8.16/config.guess
CONFIG_SUB_OVERRIDE=	../sqlite-2.8.16/config.sub

CFLAGS+=		-DUINT32_TYPE=u_int32_t -DUINT16_TYPE=u_int16_t \
			-DUINT8_TYPE=u_int8_t -DINTPTR_TYPE=long

PKGCONFIG_OVERRIDE=	${WRKDIR}/sqlite-2.8.16/sqlite.pc.in

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	${INSTALL_MAN} ${WRKDIR}/sqlite-2.8.16/sqlite.1 ${PREFIX}/man/man1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
