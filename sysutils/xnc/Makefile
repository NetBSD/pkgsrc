# $NetBSD: Makefile,v 1.8 2003/03/22 05:26:53 dillo Exp $

DISTNAME=	xnc-4.4.7.src
PKGNAME=	xnc-4.4.7
PKGREVISION=	2
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
	for f in ives.1 xjpegroot.1 xnc.1 xnlaunch.1; \
	do \
		${INSTALL_MAN} ${WRKSRC}/yo-man/$$f ${PREFIX}/man/man1/; \
	done
	${INSTALL_MAN} ${WRKSRC}/yo-man/es.1 ${PREFIX}/man/man1/iedit.1
	${INSTALL_MAN} ${WRKSRC}/yo-man/vs.1 ${PREFIX}/man/man1/iview.1

.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
