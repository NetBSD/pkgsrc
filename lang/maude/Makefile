# $NetBSD: Makefile,v 1.24 2011/04/19 19:18:40 asau Exp $
#

DISTNAME=	Maude-2.6
PKGNAME=	maude-2.6
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/ \
		http://maude.cs.uiuc.edu/download/current/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://maude.cs.uiuc.edu/
COMMENT=	System for equational and rewriting logic specification/programming
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=$(PREFIX)/share/$(PKGBASE)
USE_LANGUAGES=	c c++
USE_TOOLS+=	flex bison
TEST_TARGET=	check

post-install:
	cd $(WRKSRC)/src/Main && $(INSTALL_DATA) *.maude \
		$(DESTDIR)$(PREFIX)/share/$(PKGBASE)

.include "../../devel/buddy/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/libtecla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
