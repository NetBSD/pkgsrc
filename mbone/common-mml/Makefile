# $NetBSD: Makefile,v 1.8 2004/10/03 00:12:57 tv Exp $
#

DISTNAME=	common-1.2.0
PKGNAME=	common-mml-1.2.0
PKGREVISION=	1
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/index.html
COMMENT=	Common multimedia library required by mbone tools

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/common
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# this does ipv6 ONLY ;(
# .if ${USE_INET6} == "YES"
# CONFIGURE_ARGS+=	--enable-ipv6
# .endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/common-mml
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/common-mml

do-test:
	${WRKSRC}/test-libcommon

.include "../../mk/bsd.pkg.mk"
