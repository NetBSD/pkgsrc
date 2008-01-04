# $NetBSD: Makefile,v 1.15 2008/01/04 06:28:55 obache Exp $
#

DISTNAME=	bbappconf-0.0.2
PKGREVISION=	1
CATEGORIES=	misc x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbtools/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbtools.sourceforge.net/download.php?file=1
COMMENT=	Configure the behaviour of an application under Blackbox

USE_LANGUAGES=		c c++
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

post-patch:
	${SED} -e 's,@PREFIX@,${PREFIX},' ${WRKSRC}/data/bbappconf.1.tmp > \
		${WRKSRC}/data/bbappconf.1
	${SED} -e 's,@PREFIX@,${PREFIX},' ${WRKSRC}/data/README.bbappconf > \
		${WRKSRC}/data/README.bbappconf.tmp
	${MV} ${WRKSRC}/data/README.bbappconf.tmp ${WRKSRC}/data/README.bbappconf

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/data/bbappconf.1 ${PREFIX}/${PKGMANDIR}/man1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
