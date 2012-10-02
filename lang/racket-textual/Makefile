# $NetBSD: Makefile,v 1.14 2012/10/02 20:11:51 asau Exp $

PKGNAME=	racket-textual-5.3
PKGREVISION=	1
DISTNAME=	$(PKGNAME_NOREV)-src-unix
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

CONFLICTS+=	drscheme-[0-9]* mzscheme-[0-9]* racket-[0-9]*

PATCHDIR=	$(.CURDIR)/../../lang/racket/patches

WRKSRC=		$(WRKDIR)/$(PKGNAME_NOREV)

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src
CONFIGURE_ARGS=	--enable-pthread
USE_LANGUAGES=	c c++
MAKE_JOBS_SAFE=	no
UNLIMIT_RESOURCES=	datasize

LDFLAGS.DragonFly+=	-rdynamic

CHECK_INTERPRETER_SKIP=	lib/racket/collects/meta/build/sitemap/setup.py \
			lib/racket/collects/meta/build/sitemap/sitemap_gen.py \
			lib/racket/collects/meta/build/sitemap/test_sitemap_gen.py

CHECK_INTERPRETER_SKIP+=	lib/racket/collects/tests/jpr/mon-script.ss

.for f in use-c-printf.rkt use-crypt.rkt use-esd.rkt use-magick.rkt use-sndfile.rkt use-tcl.rkt use-xmmsctrl.rkt use-xosd.rkt
REPLACE_RACKET+=	collects/ffi/examples/$f
.endfor

REPLACE_INTERPRETER+=	racket
REPLACE.racket.old=	.*racket
REPLACE.racket.new=	$(LOCALBASE)/bin/racket
REPLACE_FILES.racket=	$(REPLACE_RACKET)


PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
