# $NetBSD: Makefile,v 1.4 2000/04/23 21:35:55 mbw Exp $
#

DISTNAME=	bvi-1.2.0.src
PKGNAME=	bvi-1.2.0
CATEGORIES=	editors
MASTER_SITES=	http://bvi.linuxave.net/download/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://bvi.linuxave.net/

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" \
		CPPFLAGS="-I${LOCALBASE}/include"
MAKE_ENV+=	SHELL=${SH}

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
.endif

.include "../../mk/bsd.pkg.mk"
