# $NetBSD: Makefile,v 1.2 2001/11/19 00:41:06 reinoud Exp $

DISTNAME=		sqlite-2.1.0
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

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
