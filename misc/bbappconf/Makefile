# $NetBSD: Makefile,v 1.6 2003/11/07 15:30:09 gavan Exp $
#

DISTNAME=	bbappconf-0.0.2
PKGNAME=	bbappconf-0.0.2
CATEGORIES=	misc x11 wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net
COMMENT=	Configure the behaviour of an application under Blackbox

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GCC_SHLIB=		YES
GNU_CONFIGURE=		YES

post-patch:
	${SED} -e 's,@PREFIX@,${PREFIX},' ${WRKSRC}/data/bbappconf.1.tmp > \
		${WRKSRC}/data/bbappconf.1
	${SED} -e 's,@PREFIX@,${PREFIX},' ${WRKSRC}/data/README.bbappconf > \
		${WRKSRC}/data/README.bbappconf.tmp
	${MV} ${WRKSRC}/data/README.bbappconf.tmp ${WRKSRC}/data/README.bbappconf

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/data/bbappconf.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
