# $NetBSD: Makefile,v 1.4 2001/05/17 20:28:18 jlam Exp $

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
NO_CONFIGURE=	# defined

.include "../../devel/readline/Makefile.readline"

MOREUSRDEFS=	-I${WRKINCDIR}/readline
MOREUSRLIBS=	-L${WRKLIBDIR} -lreadline -ltermcap

MAKE_ENV+=	OPT="${CXXFLAGS}"
MAKE_ENV+=	MOREUSRDEFS="${MOREUSRDEFS}"
MAKE_ENV+=	MOREUSRLIBS="${MOREUSRLIBS}"

pre-build: link-readline-headers link-readline-libs

.include "../../mk/bsd.pkg.mk"
