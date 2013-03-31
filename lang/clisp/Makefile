# $NetBSD: Makefile,v 1.95 2013/03/31 17:25:31 bsiegert Exp $
#

DISTNAME=		clisp-2.49
PKGREVISION=		14
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clisp/}
#EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://clisp.cons.org/
COMMENT=		CLISP, a Common Lisp implementation
LICENSE=		gnu-gpl-v2

# Sparc64 has assembler code problems, see
# http://sourceforge.net/tracker/index.php?func=detail&aid=952681&group_id=1355&atid=101355
NOT_FOR_PLATFORM=	*-*-sparc64
NOT_FOR_PLATFORM+=	*-*-arm

# makes the bulk build hang under MirBSD
NOT_FOR_PLATFORM+=	MirBSD-*-*

PKG_INSTALLATION_TYPES= overwrite pkgviews

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		.
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
BUILD_DIRS=		src
USE_TOOLS+=		dvipdf groff
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
