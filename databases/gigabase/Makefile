# $NetBSD: Makefile,v 1.4 2013/08/30 22:33:46 joerg Exp $
#

DISTNAME=	gigabase-3.82
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gigabase/}

MAINTAINER=	gpr@mail.ru
HOMEPAGE=	http://garret.ru/gigabase.html
COMMENT=	Object-Relational Database Management System
#LICENSE=	mit # like in the bottom of GigaBASE.htm

WRKSRC=			${WRKDIR}/gigabase
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
PTHREAD_AUTO_VARS=	yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	ac_cv_func_gethostbyname_r=no
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
