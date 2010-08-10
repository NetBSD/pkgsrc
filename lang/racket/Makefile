# $NetBSD: Makefile,v 1.3 2010/08/10 10:32:45 asau Exp $

PKGNAME=	racket-5.0.1
DISTNAME=	$(PKGNAME)-src-unix
CATEGORIES=	lang
MASTER_SITES_PLT=	http://download.racket-lang.org/installers/$(PKGVERSION_NOREV)/ \
		http://www.eecs.northwestern.edu/racket/$(PKGVERSION_NOREV)/ \
		http://www.cs.utah.edu/plt/installers/$(PKGVERSION_NOREV)/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/$(PKGVERSION_NOREV)/ \
		ftp://infogroep.be/pub/racket/installers/$(PKGVERSION_NOREV)/ \
		http://russell.cs.bilgi.edu.tr/racket-installers/$(PKGVERSION_NOREV)/
MASTER_SITES=	$(MASTER_SITES_PLT:=racket/)
EXTRACT_SUFX=	.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://racket-lang.org/
COMMENT=	Scheme-based dialect of Lisp
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	drscheme-[0-9]* mzscheme-[0-9]* racket-textual-[0-9]*

WRKSRC=		$(WRKDIR)/plt-$(PKGVERSION_NOREV)

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src
USE_LANGUAGES=	c c++
MAKE_JOBS_SAFE=	no
UNLIMIT_RESOURCES=	datasize

REPLACE_SH=	collects/tests/framework/framework-test

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
