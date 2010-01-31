# $NetBSD: Makefile,v 1.25 2010/01/31 20:24:38 asau Exp $

PLT_VERSION=		4.2.4
MASTER_SITES_PLT=	http://download.plt-scheme.org/bundles/ \
			http://www.eecs.northwestern.edu/plt-scheme/ \
			http://www.cs.utah.edu/plt/download/ \
			http://mirror.informatik.uni-tuebingen.de/mirror/plt/ \
			ftp://infogroep.be/pub/plt/bundles/ \
			http://gd.tuwien.ac.at/languages/scheme/plt/ \
			http://russell.cs.bilgi.edu.tr/plt-bundles/

DISTNAME=		mz-$(PLT_VERSION)-src-unix
PKGNAME=		mzscheme-$(PLT_VERSION)
CATEGORIES=		lang
MASTER_SITES=		$(MASTER_SITES_PLT:=$(PLT_VERSION)/mz/)
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://plt-scheme.org/
COMMENT=		R5RS and R6RS compliant Scheme

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			$(WRKDIR)/mz-$(PLT_VERSION)
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
USE_LANGUAGES=		c c++
USE_TOOLS=		pkg-config
USE_LIBTOOL=		yes
MAKE_JOBS_SAFE=		no
UNLIMIT_RESOURCES=	datasize

CHECK_INTERPRETER_SKIP=	include/plt/* lib/plt/collects/*

.include "../../mk/bsd.pkg.mk"
