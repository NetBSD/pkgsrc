# $NetBSD: Makefile,v 1.20 2003/06/10 16:51:48 jmc Exp $
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
USE_GCC_SHLIB=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
LIBS=			${LDFLAGS}
USE_PERL5=		run

REPLACE_PERL=		${WRKSRC}/misc/cicqconf

INCOMPAT_CURSES+=	NetBSD-1.[45]*-* NetBSD-1.6-* NetBSD-1.6.[1-9]-*
INCOMPAT_CURSES+=	NetBSD-1.6_*-* NetBSD-1.6.[1-9]_*-* NetBSD-1.6[A-T]-*

.include "../../devel/glib/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

.if ${MACHINE_ARCH} == "alpha"
# avoid toolchain bugs
CFLAGS:=	${CFLAGS:C/-O[0-9]*//g}
.endif
