# $NetBSD: Makefile,v 1.1.1.1 1999/11/08 09:05:40 sakamoto Exp $
#

DISTNAME=	bvi-1.2.0.src
PKGNAME=	bvi-1.2.0
CATEGORIES=	editors
MASTER_SITES=	http://bvi.linuxbox.com/download/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://bvi.linuxbox.com/

DEPENDS+=	ncurses-4.2:../../devel/ncurses

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" \
		CPPFLAGS="-I${LOCALBASE}/include"
MAKE_ENV+=	SHELL=${SH}

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.pkg.mk"
