# $NetBSD: Makefile,v 1.3 2001/02/16 14:38:20 wiz Exp $

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

.if exists(/usr/include/readline.h)
MOREUSRDEFS+=	-DHAVE_READLINE_H
MOREUSRLIBS+=	-ledit -ltermcap
.else
DEPENDS+=	readline-*:../../devel/readline
MOREUSRDEFS+=	-DHAVE_READLINE_READLINE_H
MOREUSRLIBS+=	${LDFLAGS} -lreadline -ltermcap
.endif

MAKE_ENV+=	OPT="${CXXFLAGS}"
MAKE_ENV+=	MOREUSRDEFS="${MOREUSRDEFS}"
MAKE_ENV+=	MOREUSRLIBS="${MOREUSRLIBS}"

.include "../../mk/bsd.pkg.mk"
