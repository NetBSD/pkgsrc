# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 16:20:08 jlam Exp $

DISTNAME=		sqlite-2.0.5
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
