# $NetBSD: Makefile,v 1.16 2003/05/12 12:03:12 uebayasi Exp $
#

DISTNAME=	centericq-4.9.2
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://konst.org.ua/eng/software/centericq/info.html
COMMENT=	Instant Messenger interface (ICQ2000, Yahoo!, and MSN support)

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_NCURSES=		# mvaddchnstr()
USE_CXX=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
LIBS=			${LDFLAGS}
USE_PERL5=		run

REPLACE_PERL=		${WRKSRC}/misc/cicqconf

.include "../../devel/glib/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

.if ${MACHINE_ARCH} == "alpha"
# avoid toolchain bugs
CFLAGS:=	${CFLAGS:C/-O[0-9]*//g}
.endif
