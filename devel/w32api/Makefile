# $NetBSD: Makefile,v 1.1.1.1 2001/01/30 03:20:51 minoura Exp $

DISTNAME=		w32api-0.4-20001122-bjy
PKGNAME=		w32api-0.4nb2
CATEGORIES=		devel
MASTER_SITES=		http://my.dreamwiz.com/bangjy/
WRKSRC=			${WRKDIR}/${DISTNAME:S/-bjy//}

MAINTAINER=		oki@yha.att.ne.jp
HOMEPAGE=		http://www.acc.umu.se/~anorland/gnu-win32/

BUILD_DEPENDS+=		${PREFIX}/cross/i386-netbsdpe/bin/gcc:../../cross/i386-netbsdpe

#HAS_CONFIGURE=		yes
#CONFIGURE_ARGS+=	"--prefix=${PREFIX}/cross/i386-netbsdpe"
#CONFIGURE_ENV+=		CC="${PREFIX}/cross/i386-netbsdpe/bin/gcc -I/usr/include"
#CONFIGURE_ENV+=		AS="${PREFIX}/cross/i386-netbsdpe/bin/as"
#CONFIGURE_ENV+=		DLLTOOL="${PREFIX}/cross/i386-netbsdpe/bin/dlltool"

#USE_GMAKE=		yes

# currently, don't build import libraries.
do-build:

do-install:
	${MKDIR} ${PREFIX}/cross/i386-netbsdpe/include 
	${CP} ${WRKSRC}/include/*.h ${PREFIX}/cross/i386-netbsdpe/include

.include "../../mk/bsd.pkg.mk"
