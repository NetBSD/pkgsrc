# $NetBSD: Makefile,v 1.3 2002/09/24 10:20:29 jlam Exp $
#

DISTNAME=	bbappconf-0.0.1-peak3
PKGNAME=	bbappconf-0.0.1.0.3
PKGREVISION=	1
CATEGORIES=	misc x11 wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/devel/

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
