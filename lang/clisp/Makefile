# $NetBSD: Makefile,v 1.26 2002/12/01 14:49:15 salo Exp $

DISTNAME=		clisp-2.27
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clisp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mjl@netbsd.org
HOMEPAGE=		http://clisp.cons.org/
COMMENT=		CLISP, a Common Lisp implementation

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 problems

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
CONFIGURE_ENV+=		CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}"
GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/${DISTNAME}/src
UNLIMIT_RESOURCES=	stacksize
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/avcall/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/callback/vacall_r/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/callback/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/callback/trampoline_r/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libiconv/libcharset/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libiconv/libtool ${WRKSRC}/sigsegv/libtool

post-patch:
	${CP} files/tramp-rs6000-netbsd.o ${WRKSRC}/../ffcall/callback/trampoline_r
	${CP} files/tramp-rs6000-netbsd.s ${WRKSRC}/../ffcall/callback/trampoline_r
	${CP} files/vacall-rs6000-netbsd.s ${WRKSRC}/../ffcall/callback/vacall_r

do-configure:
	cd ${WRKSRC}; \
	(cd .. ; ${SETENV} ${CONFIGURE_ENV} \
		${CONFIGURE_SCRIPT} --host=${MACHINE_GNU_PLATFORM} \
			--prefix=${PREFIX}); \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
		--with-dynamic-ffi --fsstnd=netbsd >Makefile

pre-build:
	cd ${WRKSRC}/avcall && ${MAKE}
	cd ${WRKSRC}/callback && ${MAKE}

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
