# $NetBSD: Makefile,v 1.31 2004/04/24 14:45:15 danw Exp $

DISTNAME=	ocaml-3.06
PKGREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/cristal/ocaml/${DISTNAME}/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://caml.inria.fr/ocaml/
COMMENT=	The latest implementation of the Caml dialect of ML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-x11include ${X11BASE}/include
CONFIGURE_ARGS+=	-x11lib ${X11BASE}/lib
CONFIGURE_ARGS+=	-tkdefs "-I${BUILDLINK_PREFIX.tk}/include  -I${BUILDLINK_PREFIX.tcl}/include"
CONFIGURE_ARGS+=	-tklibs "`${SH} -c '. ${TCLCONFIG_SH}; . ${TKCONFIG_SH}; ${ECHO} $$TK_LIBS $$TCL_LIBS'`"
CONFIGURE_ARGS+=	-libs "${LDFLAGS}"
CONFIGURE_ARGS+=	-with-pthread

ALL_TARGET=	world

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

post-extract:
	${CP} ${WRKSRC}/asmrun/power-elf.S ${WRKSRC}/asmrun/power-bsd.S

post-build:
	if ${TEST} ${MACHINE_ARCH} = 'i386' -o ${MACHINE_ARCH} = 'powerpc' \
		-o ${MACHINE_ARCH} = 'sparc' ; then \
		cd ${WRKSRC}; \
		${GMAKE} opt; \
		${GMAKE} opt.opt; \
	fi

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.  if ${OPSYS} != "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.prof
.  endif
.else
PLIST_SRC=	${PKGDIR}/PLIST
.endif

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
