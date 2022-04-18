# $NetBSD: Makefile,v 1.27 2022/04/18 19:09:42 adam Exp $

DISTNAME=	libzdb-3.2.2
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	https://www.tildeslash.com/libzdb/
COMMENT=	Zild Database Library, a fast thread-safe connection pooling library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	zdb.pc.in

SUBST_CLASSES+=		tput
SUBST_STAGE.tput=	pre-configure
SUBST_MESSAGE.tput=	don't break the user's terminal
SUBST_FILES.tput=	configure
SUBST_SED.tput=		-e 's,(tput[^)]*),(true),g'

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
