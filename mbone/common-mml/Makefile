# $NetBSD: Makefile,v 1.10 2005/06/01 18:23:37 wiz Exp $
#

DISTNAME=	common-1.2.0
PKGNAME=	common-mml-1.2.0
PKGREVISION=	1
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/index.html
COMMENT=	Common multimedia library required by mbone tools

WRKSRC=		${WRKDIR}/common
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

#.include "../../mk/bsd.prefs.mk"

# this does IPv6 ONLY ;(
# .if ${USE_INET6} == "YES"
# CONFIGURE_ARGS+=	--enable-ipv6
# .endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/common-mml
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/common-mml

do-test:
	${WRKSRC}/test-libcommon

.include "../../mk/bsd.pkg.mk"
