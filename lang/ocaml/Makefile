# $NetBSD: Makefile,v 1.26 2004/03/30 14:01:30 seb Exp $

DISTNAME=	ocaml-3.06
PKGREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/cristal/ocaml/${DISTNAME}/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://caml.inria.fr/ocaml/
COMMENT=	The latest implementation of the Caml dialect of ML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-cc "${CC} ${CFLAGS} ${CPPFLAGS}"
CONFIGURE_ARGS+=	-libs "${LDFLAGS}"

ALL_TARGET=	world

post-extract:
	${CP} ${WRKSRC}/asmrun/power-elf.S ${WRKSRC}/asmrun/power-bsd.S

post-build:
	if ${TEST} ${MACHINE_ARCH} = 'i386' -o ${MACHINE_ARCH} = 'powerpc' \
		-o ${MACHINE_ARCH} = 'sparc' ; then \
		cd ${WRKSRC}; \
		${GMAKE} opt; \
		${GMAKE} opt.opt; \
	fi

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.else
PLIST_SRC=	${PKGDIR}/PLIST
.endif

PTHREAD_OPTS+=	native
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
CONFIGURE_ARGS+=	-with-pthread
PLIST_SRC+=		${PKGDIR}/PLIST.threads
PLIST_SUBST+=		NATIVE_THREADS="@comment "
.else
PLIST_SUBST+=		NATIVE_THREADS=
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.common_end

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
