# $NetBSD: Makefile,v 1.19 2007/12/01 13:17:56 rillig Exp $
#

DISTNAME=	Maude-2.3
PKGNAME=	maude-2.3
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/ \
		http://maude.cs.uiuc.edu/download/current/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://maude.cs.uiuc.edu/
COMMENT=	System for equational and rewriting logic specification/programming

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	flex bison
INSTALLATION_DIRS_FROM_PLIST=yes

post-install:
	cd ${WRKSRC}/src/Main && ${INSTALL_DATA} *.maude ${PREFIX}/share/maude

.include "../../devel/buddy/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libtecla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
