# $NetBSD: Makefile,v 1.158 2024/05/07 23:52:11 gdt Exp $

DISTNAME=	unison-2.53.5
#PKGREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=bcpierce00/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/bcpierce00/unison
#HOMEPAGE+=	https://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	File-synchronization tool
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake bash
MAKE_FLAGS+=	CFLAGS=""
ALL_ENV+=	PREFIX=${PREFIX}
ALL_ENV+=	MANDIR=${PREFIX}/man
MAKE_ENV+=	HOME=${WRKDIR:Q}

.include "../../lang/ocaml/ocaml.mk"

.if (${OCAML_USE_OPT_COMPILER} == "yes")
MAKE_FLAGS+=	NATIVE=true
.else
MAKE_FLAGS+=	NATIVE=false
.endif

# bsd.prefs.mk, included also by options, must be after ocaml to get
# _PKGSRC_MKPIE set correctly.
.include "options.mk"
.include "../../mk/bsd.prefs.mk"

# \todo
#   add fsmonitor option, needing python and libinotify, or forcing it off

# Unison does not install non-man docs
INSTALLATION_DIRS+=	share/doc/unison

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/COPYING ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/CONTRIBUTING.md ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/INSTALL.md ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/NEWS.md ${DESTDIR}${PREFIX}/share/doc/unison
	# \todo See fsmonitor above.
	${RM} ${DESTDIR}${PREFIX}/bin/fsmonitor.py

TEST_TARGET=		test

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
MAKE_FLAGS+=	THREADS=true
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
