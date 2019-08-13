# $NetBSD: Makefile,v 1.114 2019/08/13 14:24:31 rjs Exp $

DISTNAME=		clisp-2.49
PKGREVISION=		26
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clisp/}
#EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://clisp.cons.org/
COMMENT=		CLISP, a Common Lisp implementation
LICENSE=		gnu-gpl-v2

# XXX: is this still current?
BROKEN_ON_PLATFORM+=	*-*-arm

BROKEN_ON_PLATFORM+=	*-*-aarch64

# makes the bulk build hang under MirBSD
BROKEN_ON_PLATFORM+=	MirBSD-*-*

MAKE_JOBS_SAFE=		no

# Installs a copy of its own depcomp, avoid libtool dependency here.
OVERRIDE_DIRDEPTH.depcomp=	0

GNU_CONFIGURE=		yes	# not really, but very close
GNU_CONFIGURE_STRICT=	no	# doesn't know --enable-option-checking
CONFIGURE_DIRS=		.
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
BUILD_DIRS=		src
USE_TOOLS+=		groff
UNLIMIT_RESOURCES=	datasize stacksize

USE_GNU_CONFIGURE_HOST=	NO	# work around broken reasoning: "configure --host=..." => cross-building
CONFIGURE_ARGS+=	--disable-maintainer-mode
CONFIGURE_ARGS+=	--fsstnd=netbsd
CONFIGURE_ARGS+=	--without-included-regex
CONFIGURE_ARGS+=	--with-gettext
MAKE_FLAGS+=		docdir=${PREFIX}/share/doc/${PKGBASE}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		elispdir="${PREFIX}/share/${PKGBASE}/emacs"
MAKE_FLAGS+=		vimdir="${PREFIX}/share/${PKGBASE}/vim"

TEST_TARGET=		check mod-check

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:Malpha} || ${MACHINE_ARCH:Mamd64} || ${MACHINE_ARCH:Mx86_64} || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-mmap
.endif

# Try to make the built-in src/malloc/gmalloc.c work with modern GCC
.if ${OPSYS} == "NetBSD"
CFLAGS+=	-fno-builtin-calloc
CFLAGS+=	-fno-builtin-malloc
CFLAGS+=	-fno-builtin-memalign
CFLAGS+=	-fno-builtin-realloc
CFLAGS+=	-fno-builtin-valloc
CFLAGS+=	-fno-builtin-free
.endif

.if $(MACHINE_ARCH:Mi386)
CFLAGS+=		-falign-functions=4	# force the assumption
.endif

.if ${OPSYS} == "SunOS"
USE_TOOLS+=	bash
CONFIG_SHELL=	${TOOLS_PATH.bash}
.endif

post-extract:
	(cd ${WRKSRC} && ${CP} -p src/gllib/mbrtowc.c modules/syscalls/gllib)

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsigsegv+=	libsigsegv>=2.4
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
