# $NetBSD: Makefile,v 1.31 2017/01/19 18:52:14 agc Exp $

PKGNAME=	racket-minimal-6.7
DISTNAME=	$(PKGNAME_NOREV)-src
CATEGORIES=	lang
MASTER_SITES_PLT=	http://download.racket-lang.org/installers/$(PKGVERSION_NOREV)/
MASTER_SITES_PLT+=	http://www.eecs.northwestern.edu/racket/$(PKGVERSION_NOREV)/
MASTER_SITES_PLT+=	http://www.cs.utah.edu/plt/installers/$(PKGVERSION_NOREV)/
MASTER_SITES_PLT+=	http://mirror.informatik.uni-tuebingen.de/mirror/racket/$(PKGVERSION_NOREV)/
MASTER_SITES_PLT+=	ftp://infogroep.be/pub/racket/installers/$(PKGVERSION_NOREV)/
# Pre-release:
#MASTER_SITES_PLT=	http://pre-release.racket-lang.org/installers/
MASTER_SITES=	$(MASTER_SITES_PLT)
EXTRACT_SUFX=	.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://racket-lang.org/
COMMENT=	Scheme-based dialect of Lisp
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	drscheme-[0-9]* mzscheme-[0-9]* racket-[0-9]*

PATCHDIR=	${.CURDIR}/../../lang/racket/patches

WRKSRC=		$(WRKDIR)/racket-$(PKGVERSION_NOREV)

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src
CONFIGURE_ARGS=	--enable-pthread
USE_LANGUAGES=	c c++
MAKE_JOBS_SAFE=	no
UNLIMIT_RESOURCES=	datasize
OVERRIDE_DIRDEPTH=	3

LDFLAGS.DragonFly+=	-rdynamic

CHECK_INTERPRETER_SKIP=	lib/racket/collects/meta/build/sitemap/setup.py \
			lib/racket/collects/meta/build/sitemap/sitemap_gen.py \
			lib/racket/collects/meta/build/sitemap/test_sitemap_gen.py

CHECK_INTERPRETER_SKIP+=	lib/racket/collects/tests/jpr/mon-script.ss

# REPLACE_INTERPRETER+=	racket
# REPLACE.racket.old=	.*racket
# REPLACE.racket.new=	$(LOCALBASE)/bin/racket
# REPLACE_FILES.racket=	$(REPLACE_RACKET)

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
