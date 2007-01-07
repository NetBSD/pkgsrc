# $NetBSD: Makefile,v 1.13 2007/01/07 09:14:00 rillig Exp $
#

DISTNAME=	bbappconf-0.0.2
PKGREVISION=	1
CATEGORIES=	misc x11 wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	Configure the behaviour of an application under Blackbox

USE_LANGUAGES=		c c++
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

.include "../../mk/x11.buildlink3.mk"

post-patch:
	${SED} -e 's,@PREFIX@,${PREFIX},' ${WRKSRC}/data/bbappconf.1.tmp > \
		${WRKSRC}/data/bbappconf.1
	${SED} -e 's,@PREFIX@,${PREFIX},' ${WRKSRC}/data/README.bbappconf > \
		${WRKSRC}/data/README.bbappconf.tmp
	${MV} ${WRKSRC}/data/README.bbappconf.tmp ${WRKSRC}/data/README.bbappconf

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/data/bbappconf.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
