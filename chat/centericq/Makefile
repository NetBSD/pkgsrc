# $NetBSD: Makefile,v 1.2 2002/03/10 16:56:09 wiz Exp $
#

DISTNAME=	centericq-4.6.5
CATEGORIES=	chat
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://konst.org.ua/eng/software/centericq/info.html
COMMENT=	Instant Messenger interface (ICQ2000, Yahoo!, and MSN support)

GNU_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink.mk"
.include "../../lang/gcc/Makefile.gcc"
.include "../../devel/libsigc++/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
