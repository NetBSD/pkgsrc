# $NetBSD: Makefile,v 1.50 2020/01/09 15:56:11 ryoon Exp $

.include "Makefile.common"
PKGREVISION=	1

COMMENT=	GIF image format library

CONFLICTS+=	libungif-[0-9]*

INSTALL_TARGET= 	install-include
INSTALL_TARGET+= 	install-lib

post-install:
	${INSTALL_LIB} ${WRKSRC}/libutil.a \
		${DESTDIR}${PREFIX}/lib/libgifutil.a
	${INSTALL_LIB} ${WRKSRC}/libutil.so \
		${DESTDIR}${PREFIX}/lib/libgifutil.so

.include "../../mk/bsd.pkg.mk"
