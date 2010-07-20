# $NetBSD: Makefile,v 1.2 2010/07/20 03:12:18 obache Exp $

PKGNAME=	racket-5.0
DISTNAME=	$(PKGNAME)-src-unix
CATEGORIES=	lang
MASTER_SITES_PLT=	http://download.racket-lang.org/installers/5.0/ \
		http://www.eecs.northwestern.edu/racket/5.0/ \
		http://www.cs.utah.edu/plt/installers/5.0/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/5.0/ \
		ftp://infogroep.be/pub/racket/installers/5.0/ \
		http://russell.cs.bilgi.edu.tr/racket-installers/5.0/
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
