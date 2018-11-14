# $NetBSD: Makefile,v 1.127 2018/11/14 22:22:14 kleink Exp $

DISTNAME=	unison-2.48.15
PKGREVISION=	15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=bcpierce00/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	File-synchronization tool
LICENSE=	gnu-gpl-v3

# File "/data/scratch/net/unison/work/src/fswatch.mli", line 18, characters 17-29:
# Error: Unbound module Prefs
MAKE_JOBS_SAFE=	no

.if (${MACHINE_ARCH} == "arm")
BUILDLINK_ABI_DEPENDS.ocaml+=	ocaml>=3.12.0nb2
.else
BUILDLINK_ABI_DEPENDS.ocaml+=	ocaml>=3.11.2
.endif
BUILDLINK_API_DEPENDS.ocaml-lablgtk+= ocaml-lablgtk>=2.16.0

# docs: unison-manual.pdf/html/ps/dvi
#WRKSRC=		${WRKDIR}/src
USE_TOOLS+=	gmake
MAKE_FLAGS+=	CFLAGS="" -C src
MAKE_ENV+=	HOME=${WRKDIR:Q}

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.include "../../mk/ocaml.mk"

.if (${OCAML_USE_OPT_COMPILER} == "true")
MAKE_FLAGS+=	NATIVE=true
.else
MAKE_FLAGS+=	NATIVE=false
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
MAKE_FLAGS+=	THREADS=true
.endif

BUILD_TARGET=	buildexecutable

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/unison

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/BUGS.txt ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/src/CONTRIB ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/src/COPYING ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/src/NEWS ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/src/README ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/src/ROADMAP.txt ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/src/TODO.txt ${DESTDIR}${PREFIX}/share/doc/unison

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
