# $NetBSD: Makefile,v 1.3 2001/01/12 12:33:18 dent Exp $
#

DISTNAME=	tn5250-0.12.51
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blarg.net/users/mmadore/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.linux-sna.org/software/5250/

DEPENDS+=	ncurses>=4.2:../../devel/ncurses

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
