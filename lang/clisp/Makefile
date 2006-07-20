# $NetBSD: Makefile,v 1.55 2006/07/20 23:05:43 perry Exp $

DISTNAME=	clisp-2.39
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP, a Common Lisp implementation

# Sparc64 has assembler code problems, see
# http://sourceforge.net/tracker/index.php?func=detail&aid=952681&group_id=1355&atid=101355
NOT_FOR_PLATFORM=	*-*-sparc64

PKG_INSTALLATION_TYPES= overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:Malpha} || ${MACHINE_ARCH:Mamd64} || ${MACHINE_ARCH:Mx86_64} || ${OPSYS} == "DragonFly"
MODULES+=		--disable-mmap
.endif

USE_PKGLOCALEDIR=	YES
BUILD_DIRS=		src
CONFIGURE_DIRS=		. modules/i18n modules/syscalls modules/pcre modules/rawsock \
			modules/readline modules/regexp modules/wildcard modules/zlib
CONFIGURE_ENV+=		CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q} CPPFLAGS=${CPPFLAGS:M*:Q}
GNU_CONFIGURE=		YES
UNLIMIT_RESOURCES=	stacksize
USE_LIBTOOL=		YES
USE_GNU_READLINE=	YES
MODULES+=		--with-module=pcre --with-module=rawsock
MODULES+=		--with-module=wildcard --with-module=zlib
CONFIGURE_ARGS+=	${MODULES}
TEST_TARGET=		check

post-patch:
	${CP} files/tramp-rs6000-netbsd.o ${WRKSRC}/ffcall/callback/trampoline_r
	${CP} files/tramp-rs6000-netbsd.s ${WRKSRC}/ffcall/callback/trampoline_r
	${CP} files/vacall-rs6000-netbsd.s ${WRKSRC}/ffcall/callback/vacall_r

post-configure:
	cd ${WRKSRC}/src && \
	./makemake --prefix=${PREFIX} --with-readline --with-gettext \
		--with-dynamic-ffi --fsstnd=netbsd ${MODULES} >Makefile

pre-build:
	cd ${WRKSRC}/src/avcall && ${MAKE}
	cd ${WRKSRC}/src/callback && ${MAKE}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
