# $NetBSD: Makefile,v 1.8 2002/09/29 06:20:23 jlam Exp $
#

DISTNAME=	centericq-4.6.5
CATEGORIES=	chat
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://konst.org.ua/eng/software/centericq/info.html
COMMENT=	Instant Messenger interface (ICQ2000, Yahoo!, and MSN support)

USE_BUILDLINK2=	yes
USE_NCURSES=	yes
USE_CXX=	yes
GNU_CONFIGURE=	yes
LIBS=		${LDFLAGS}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/libsigc++/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

.if ${MACHINE_ARCH} == "alpha"
# avoid toolchain bugs
CFLAGS:=	${CFLAGS:C/-O[0-9]*//g}
.endif

