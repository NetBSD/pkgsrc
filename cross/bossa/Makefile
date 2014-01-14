# $NetBSD: Makefile,v 1.1 2014/01/14 15:36:59 reinoud Exp $

PKGNAME=	bossa-20140109
DISTNAME=	b-o-s-s-a-code-05bfcc39bc0453c3028b1161175b95a81af7a901
CATEGORIES=	comms
MASTER_SITES=	http://sourceforge.net/code-snapshots/git/b/b-/b-o-s-s-a/code.git/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://sourceforge.net/code-snapshots/git/b/b-/b-o-s-s-a/code.git/
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
