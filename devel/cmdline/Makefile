# $NetBSD: Makefile,v 1.7 2001/06/11 02:05:09 jlam Exp $

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

USE_LIBTOOL=	# defined

.include "../../devel/readline/buildlink.mk"

MOREUSRDEFS=	-I${BUILDLINK_DIR}/include/readline
MOREUSRLIBS=	-L${BUILDLINK_DIR}/lib -lreadline -ltermcap

MAKE_ENV+=	OPT="${CXXFLAGS}"
MAKE_ENV+=	MOREUSRDEFS="${MOREUSRDEFS}"
MAKE_ENV+=	MOREUSRLIBS="${MOREUSRLIBS}"

.include "../../mk/bsd.pkg.mk"
