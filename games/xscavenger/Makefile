# $NetBSD: Makefile,v 1.22 2017/09/06 10:40:29 wiz Exp $
#

DISTNAME=	xscavenger-1.4.4
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://www.xdr.com/dash/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.xdr.com/dash/scavenger.html
COMMENT=	Loderunner clone with sound for X11

USE_IMAKE=		yes
CONFIGURE_DIRS=		src
BUILD_DIRS=		${CONFIGURE_DIRS}
NO_INSTALL_MANPAGES=	yes

CPPFLAGS+=	-DSOUNDDEV="\"${DEVOSSSOUND}\""

INSTALLATION_DIRS=	${PKGMANDIR}/man6 share/doc/scavenger

.include "../../mk/oss.buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/scavenger.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/
	${INSTALL_MAN} ${WRKSRC}/DOC ${DESTDIR}${PREFIX}/share/doc/scavenger

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
