# $NetBSD: Makefile,v 1.1.1.1 1999/08/04 17:00:26 rh Exp $
#

DISTNAME=	tn5250-0.12.51
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blarg.net/users/mmadore/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.blarg.net/~mmadore/5250.html

DEPENDS+=	ncurses-4.2:../../devel/ncurses

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
