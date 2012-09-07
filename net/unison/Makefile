# $NetBSD: Makefile,v 1.57 2012/09/07 19:17:22 adam Exp $

DISTNAME=	unison-2.40.63
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	http://www.seas.upenn.edu/~bcpierce/unison/download/releases/stable/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	File-synchronization tool
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.if (${MACHINE_ARCH} == "arm")
BUILDLINK_ABI_DEPENDS.ocaml+=	ocaml>=3.12.0nb2
.else
BUILDLINK_ABI_DEPENDS.ocaml+=	ocaml>=3.11.2
.endif

# docs: unison-manual.pdf/html/ps/dvi
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake
MAKE_FLAGS+=	CFLAGS=""
MAKE_ENV+=	HOME=${WRKDIR:Q}

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH}=="arm")
MAKE_FLAGS+=	NATIVE=true
.else
MAKE_FLAGS+=	NATIVE=false
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
MAKE_FLAGS+=	THREADS=true
.endif

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/unison

post-install:
	${INSTALL_MAN} ${WRKSRC}/BUGS.txt ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/CONTRIB ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/ROADMAP.txt ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/TODO.txt ${DESTDIR}${PREFIX}/share/doc/unison

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
