# $NetBSD: Makefile,v 1.3 2001/02/23 20:10:10 jtb Exp $

DISTNAME=		geomview-1.8.0
CATEGORIES=		graphics math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=geomview/}

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.geomview.org
COMMENT=		Interactive geometry viewing program

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_MOTIF=		YES
USE_MESA=		YES
EVAL_PREFIX+=		MESA_PREFIX=Mesa

CONFIGURE_ARGS+=	--without-xforms
CONFIGURE_ARGS+=	--with-opengl=${MESA_PREFIX}
CONFIGURE_ARGS+=	--with-motif=${MOTIFBASE}
CONFIGURE_ENV+=		"CPPFLAGS=-Dunix -Dalloca=__builtin_alloca"

INFO_FILES=		geomview

.include "../../mk/bsd.pkg.mk"
