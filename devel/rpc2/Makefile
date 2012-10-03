# $NetBSD: Makefile,v 1.38 2012/10/03 21:55:54 wiz Exp $
#

DISTNAME=	rpc2-2.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.coda.cs.cmu.edu/pub/rpc2/src/

MAINTAINER=	phil@cs.wwu.edu
# also gdt@NetBSD.org
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pkg-config
# Earlier we had a patch to put
# AC_CHECK_PROGS(YACC, 'bison -y' byacc yacc)
# in configure.in, but with yacc in USE_TOOLS, then there
# should always be at least yacc and this is no
# longer necessary.
USE_TOOLS+=		lex yacc

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
