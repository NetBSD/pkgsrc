# $NetBSD: Makefile,v 1.2 2000/01/15 18:46:33 jlam Exp $
#

DISTNAME=	tn5250-0.12.51
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blarg.net/users/mmadore/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.blarg.net/~mmadore/5250.html

DEPENDS+=	ncurses>=4.2:../../devel/ncurses

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
