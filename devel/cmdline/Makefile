# $NetBSD: Makefile,v 1.10 2002/10/25 18:29:40 wiz Exp $

DISTNAME=	CmdLine
PKGNAME=	cmdline-${PKG_VERS}
DIST_VERS=	1.04
PKG_VERS=	1.05nb1
CATEGORIES=	devel
MASTER_SITES=	http://www.enteract.com/~bradapp/ftp/src/libs/C++/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.enteract.com/~bradapp/ftp/src/libs/C++/CmdLine.html
COMMENT=	C++ library for parsing command arguments

DIST_SUBDIR=	cmdline-${DIST_VERS}

USE_BUILDLINK2=		# defined
USE_LIBTOOL=		# defined

MOREUSRDEFS=	-I${BUILDLINK_PREFIX.readline}/include/readline
MOREUSRDEFS+=	-I${BUILDLINK_PREFIX.readline}/include/readline/readline
MOREUSRLIBS=	-L${BUILDLINK_PREFIX.readline}/lib -lreadline -ltermcap

MAKE_ENV+=	OPT="${CXXFLAGS}"
MAKE_ENV+=	MOREUSRDEFS="${MOREUSRDEFS}"
MAKE_ENV+=	MOREUSRLIBS="${MOREUSRLIBS}"

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
