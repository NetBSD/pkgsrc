# $NetBSD: Makefile,v 1.2 2014/01/20 22:10:37 reinoud Exp $

PKGNAME=	bossa-20140109
DISTNAME=	b-o-s-s-a-code-05bfcc39bc0453c3028b1161175b95a81af7a901
CATEGORIES=	comms
EXTRACT_SUFX=	.zip

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/b-o-s-s-a/
COMMENT=	Open source SAM-BA compatible Atmel ARM programmer
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=      bin

post-patch:
	${CP} files/* ${WRKSRC}/src/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin


USE_LANGUAGES=	c++
USE_TOOLS=	gmake

.include "../../devel/readline/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
