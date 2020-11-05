# $NetBSD: Makefile,v 1.85 2020/11/05 09:08:33 ryoon Exp $

PKGNAME=		racket-6.12
PKGREVISION=		10
DISTNAME=		${PKGNAME_NOREV}-src
CATEGORIES=		lang
MASTER_SITES_PLT=	https://download.racket-lang.org/installers/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	https://mirror.racket-lang.org/installers/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	https://plt.eecs.northwestern.edu/racket-mirror/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	https://www.cs.utah.edu/plt/installers/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	http://mirror.csclub.uwaterloo.ca/racket/racket-installers/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	https://racket.infogroep.be/${PKGVERSION_NOREV}/
# Pre-release:
#MASTER_SITES_PLT=	http://pre-release.racket-lang.org/installers/
MASTER_SITES=		${MASTER_SITES_PLT}
EXTRACT_SUFX=		.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://racket-lang.org/
COMMENT=	Scheme-based dialect of Lisp
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	drscheme-[0-9]* mzscheme-[0-9]* racket-textual-[0-9]*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
CONFIGURE_ARGS=		--enable-pthread
USE_LANGUAGES=		c c++
USE_TOOLS=		pkg-config gmake
UNLIMIT_RESOURCES=	virtualsize datasize cputime
MAKE_ENV+=		"PAXCTL=${TOOLS_PLATFORM.paxctl}"

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
LDFLAGS.DragonFly+=	-rdynamic

CHECK_INTERPRETER_SKIP=	collects/meta/build/sitemap/setup.py \
			collects/meta/build/sitemap/test_sitemap_gen.py

CHECK_INTERPRETER_SKIP=	lib/racket/collects/meta/build/sitemap/setup.py \
			lib/racket/collects/meta/build/sitemap/sitemap_gen.py \
			lib/racket/collects/meta/build/sitemap/test_sitemap_gen.py

CHECK_INTERPRETER_SKIP+=	lib/racket/collects/tests/jpr/mon-script.ss

CHECK_RELRO_SKIP=	bin/mred bin/mzscheme

.for f in use-c-printf.rkt use-crypt.rkt use-esd.rkt use-magick.rkt use-sndfile.rkt use-tcl.rkt use-xmmsctrl.rkt use-xosd.rkt
REPLACE_RACKET+=	share/pkgs/racket-doc/ffi/examples/${f}
.endfor

REPLACE_INTERPRETER+=	racket
REPLACE.racket.old=	.*racket
REPLACE.racket.new=	${LOCALBASE}/bin/racket
REPLACE_FILES.racket=	${REPLACE_RACKET}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
