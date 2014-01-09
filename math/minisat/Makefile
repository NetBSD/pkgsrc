# $NetBSD: Makefile,v 1.2 2014/01/09 14:38:33 jperkin Exp $

DISTNAME=	minisat-2.2.0
CATEGORIES=	math
MASTER_SITES=	http://minisat.se/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minisat.se/
COMMENT=	Minimalistic yet highly efficient SAT solver
LICENSE=	mit

WRKSRC=		$(WRKDIR)/minisat
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
#BUILD_DIRS=	core simp
BUILD_DIRS=	simp
MAKE_ENV=	MROOT=$(WRKSRC)
BUILD_TARGET=	# empty

INSTALLATION_DIRS+=	bin

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/simp/minisat \
		$(DESTDIR)$(PREFIX)/bin/minisat

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
