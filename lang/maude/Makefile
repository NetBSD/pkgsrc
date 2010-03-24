# $NetBSD: Makefile,v 1.22 2010/03/24 19:43:25 asau Exp $
#

DISTNAME=	Maude-2.3
PKGNAME=	maude-2.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/ \
		http://maude.cs.uiuc.edu/download/current/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://maude.cs.uiuc.edu/
COMMENT=	System for equational and rewriting logic specification/programming

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	flex bison
AUTO_MKDIRS=		yes

post-install:
	cd ${WRKSRC}/src/Main && ${INSTALL_DATA} *.maude \
		${DESTDIR}${PREFIX}/share/maude

.include "../../devel/buddy/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libtecla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
