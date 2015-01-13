# $NetBSD: Makefile,v 1.6 2015/01/13 20:25:13 he Exp $
#

DISTNAME=	dbeacon-0.3.9.1
PKGREVISION=	4
CATEGORIES=	mbone
MASTER_SITES=	http://fivebits.net/files/dbeacon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fivebits.net/proj/dbeacon/
COMMENT=	Distributed IPv4/IPv6 multicast beacon
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
BUILD_DEFS+=	IPV6_READY

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/dbeacon
INSTALLATION_DIRS+=	share/doc/dbeacon

#INSTALL_UNSTRIPPED=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbeacon ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/dbeacon.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for f in FAQ PROTOCOL large_scale_beaconing.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DESTDIR}${PREFIX}/share/doc/dbeacon
.endfor
.for f in apache-matrix-conf checkmatrix.sh dbeacon.conf.sample matrix.conf.sample matrix.pl xml2txt.pl
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${DESTDIR}${PREFIX}/share/examples/dbeacon
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/matrix.conf.5 ${DESTDIR}${PREFIX}/share/examples/dbeacon

.include "../../mk/bsd.pkg.mk"
