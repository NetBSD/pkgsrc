# $NetBSD: Makefile,v 1.2 2011/06/18 02:45:13 obache Exp $
#

DISTNAME=	gigabase-3.82
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gigabase/}

MAINTAINER=	gpr@mail.ru
HOMEPAGE=	http://garret.ru/gigabase.html
COMMENT=	Object-Relational Database Management System
#LICENSE=	mit # like in the bottom of GigaBASE.htm

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/gigabase
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
PTHREAD_AUTO_VARS=	yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
