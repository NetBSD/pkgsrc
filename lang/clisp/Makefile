# $NetBSD: Makefile,v 1.50 2006/03/14 07:17:23 wiz Exp $

DISTNAME=	clisp-2.38
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP, a Common Lisp implementation

# XXX: uncomment if still true (commented out during update to 2.38)
#NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64 *-*-x86_64	# severe LP64 problems

PKG_INSTALLATION_TYPES= overwrite pkgviews

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
BUILDLINK_DEPENDS.zlib+=	zlib>=1.2
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
