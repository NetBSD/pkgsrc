# $NetBSD: Makefile,v 1.37 2004/10/03 00:15:00 tv Exp $

DISTNAME=		clisp-2.33
PKGREVISION=	1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clisp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mjl@NetBSD.org
HOMEPAGE=		http://clisp.cons.org/
COMMENT=		CLISP, a Common Lisp implementation

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 problems

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
CONFIGURE_ENV+=		CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
			gt_cv_func_gnugettext2_libintl=yes
GNU_CONFIGURE=		YES
UNLIMIT_RESOURCES=	stacksize
USE_LIBTOOL=		YES
USE_GNU_READLINE=	YES

post-patch:
	${CP} files/tramp-rs6000-netbsd.o ${WRKSRC}/../ffcall/callback/trampoline_r
	${CP} files/tramp-rs6000-netbsd.s ${WRKSRC}/../ffcall/callback/trampoline_r
	${CP} files/vacall-rs6000-netbsd.s ${WRKSRC}/../ffcall/callback/vacall_r

do-configure:
	cd ${WRKSRC} && \
	(cd .. ; ${SETENV} ${CONFIGURE_ENV} \
		${CONFIGURE_SCRIPT} --host=${MACHINE_GNU_PLATFORM} \
			--prefix=${PREFIX}) && \
	./makemake --prefix=${LOCALBASE} --with-readline --with-gettext \
		--with-dynamic-ffi --fsstnd=netbsd >Makefile

pre-build:
	cd ${WRKSRC}/avcall && ${MAKE}
	cd ${WRKSRC}/callback && ${MAKE}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
