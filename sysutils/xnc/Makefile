# $NetBSD: Makefile,v 1.7 2002/09/23 23:35:49 jlam Exp $

DISTNAME=	xnc-4.4.7.src
PKGNAME=	xnc-4.4.7
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.xnc.dubna.su/src/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://xnc.dubna.su/
COMMENT=	File manager for X Window

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xnc
	${INSTALL_DATA} ${WRKSRC}/Docs/* ${PREFIX}/share/doc/xnc
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/yo-man/*.1 ${PREFIX}/man/man1/

.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
