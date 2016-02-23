# $NetBSD: Makefile,v 1.106 2016/02/23 15:19:23 joerg Exp $
#

DISTNAME=		clisp-2.49
PKGREVISION=		21
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clisp/}
#EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://clisp.cons.org/
COMMENT=		CLISP, a Common Lisp implementation
LICENSE=		gnu-gpl-v2

# XXX: is this still current?
BROKEN_ON_PLATFORM+=	*-*-arm

# makes the bulk build hang under MirBSD
BROKEN_ON_PLATFORM+=	MirBSD-*-*

MAKE_JOBS_SAFE=		no

# Installs a copy of its own depcomp, avoid libtool dependency here.
OVERRIDE_DIRDEPTH.depcomp=	0

GNU_CONFIGURE=		yes
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
