# $NetBSD: Makefile,v 1.23 2010/05/19 11:55:43 asau Exp $
#

DISTNAME=	Maude-2.4
PKGNAME=	maude-2.4
#PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/ \
		http://maude.cs.uiuc.edu/download/current/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://maude.cs.uiuc.edu/
COMMENT=	System for equational and rewriting logic specification/programming
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--datadir=$(PREFIX)/share/$(PKGBASE)
USE_LANGUAGES=	c c++
USE_TOOLS+=	flex bison
AUTO_MKDIRS=		yes

post-install:
	cd ${WRKSRC}/src/Main && ${INSTALL_DATA} *.maude \
		${DESTDIR}${PREFIX}/share/maude

.include "../../devel/buddy/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/libtecla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
