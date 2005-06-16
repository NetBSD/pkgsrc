# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:41 jlam Exp $
#

DISTNAME=		amsn-0_94
PKGNAME=		${DISTNAME:S/_/./}
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amsn/}

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://amsn.sourceforge.net/
COMMENT=		"Alvaro's MSN messenger client"

NO_CONFIGURE=		YES
NO_BUILD=		YES
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/amsn
	${CP} -R ${WRKSRC}/* ${PREFIX}/share/amsn
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps
	${CP} -R ${WRKSRC}/icons/32x32/* ${PREFIX}/share/pixmaps
	${LN} -sf ${PREFIX}/share/amsn/amsn ${PREFIX}/bin/amsn
	${CHMOD} +x ${PREFIX}/share/amsn/amsn

.include "../../security/tcl-tls/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
