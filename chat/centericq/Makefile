# $NetBSD: Makefile,v 1.6 2002/03/25 17:18:32 hubertf Exp $
#

DISTNAME=	centericq-4.6.5
CATEGORIES=	chat
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://konst.org.ua/eng/software/centericq/info.html
COMMENT=	Instant Messenger interface (ICQ2000, Yahoo!, and MSN support)

GNU_CONFIGURE=	yes
USE_NCURSES=	yes

GCC_VERSION!=           gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
.include "../../lang/gcc/Makefile.gcc"
.endif

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/libsigc++/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
