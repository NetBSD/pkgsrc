# $NetBSD: Makefile,v 1.36 2024/05/29 16:31:41 adam Exp $

DISTNAME=	libzdb-3.2.3
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tildeslash.com/libzdb/
COMMENT=	Zild Database Library, a fast thread-safe connection pooling library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

USE_CXX_FEATURES+=	c++17

PKGCONFIG_OVERRIDE+=	zdb.pc.in

SUBST_CLASSES+=		tput
SUBST_STAGE.tput=	pre-configure
SUBST_MESSAGE.tput=	don't break the user's terminal
SUBST_FILES.tput=	configure
SUBST_SED.tput=		-e 's,(tput[^)]*),(true),g'

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
