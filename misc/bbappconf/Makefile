# $NetBSD: Makefile,v 1.4 2002/12/18 04:34:42 jschauma Exp $
#

DISTNAME=	bbappconf-0.0.2
PKGNAME=	bbappconf-0.0.2
CATEGORIES=	misc x11 wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://bbtools.windsofstorm.net
COMMENT=	Configure the behaviour of an application under Blackbox

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
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
