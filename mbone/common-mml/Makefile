# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 09:46:00 hubertf Exp $
#

DISTNAME=	common-1.2.0
PKGNAME=	common-mml-1.2.0
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/index.html

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/common

# this does ipv6 ONLY ;(
# .if ${USE_INET6} == "YES"
# CONFIGURE_ARGS+=	--enable-ipv6
# .endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/common-mml
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/common-mml

.include "../../mk/bsd.pkg.mk"
