# $NetBSD: Makefile,v 1.5 2011/08/01 11:45:43 asau Exp $

PKGNAME=	racket-textual-5.1.1
DISTNAME=	$(PKGNAME)-src-unix
CATEGORIES=	lang
MASTER_SITES_PLT=	http://download.racket-lang.org/installers/$(PKGVERSION_NOREV)/ \
		http://www.eecs.northwestern.edu/racket/$(PKGVERSION_NOREV)/ \
		http://www.cs.utah.edu/plt/installers/$(PKGVERSION_NOREV)/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/$(PKGVERSION_NOREV)/ \
		ftp://infogroep.be/pub/racket/installers/$(PKGVERSION_NOREV)/ \
		http://russell.cs.bilgi.edu.tr/racket-installers/$(PKGVERSION_NOREV)/
MASTER_SITES=	$(MASTER_SITES_PLT:=racket-textual/)
EXTRACT_SUFX=	.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://racket-lang.org/
COMMENT=	Scheme-based dialect of Lisp
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_INTERPRETER+=	racket
REPLACE.racket.old=	/usr/bin/env racket
REPLACE.racket.new=	${PREFIX}/bin/racket
REPLACE_FILES.racket=	collects/ffi/examples/*.rkt

CONFLICTS+=	drscheme-[0-9]* mzscheme-[0-9]* racket-[0-9]*

WRKSRC=		$(WRKDIR)/$(PKGNAME_NOREV)

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src
USE_LANGUAGES=	c c++
MAKE_JOBS_SAFE=	no
UNLIMIT_RESOURCES=	datasize

.include "../../mk/bsd.pkg.mk"
