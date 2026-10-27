# $NetBSD: Makefile,v 1.45 2026/10/27 15:49:59 ktnb Exp $

DISTNAME=		scheme48-1.9.3
CATEGORIES=		lang
MASTER_SITES=		http://s48.org/1.9.3/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://s48.org/
#HOMEPAGE+=		https://codeberg.org/s48/scheme48
COMMENT=		The Scheme Underground implementation of R5RS
LICENSE=		modified-bsd

MAKE_JOBS_SAFE=		no

# bin/scheme-r5rs
CONFLICTS+=		gambc-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${PREFIX}/share/doc/${PKGNAME_NOREV} \
		--htmldir=${PREFIX}/share/doc/${PKGNAME_NOREV}/html \
		--mandir=${PREFIX}/${PKGMANDIR}
USE_TOOLS+=	gmake pax
BUILD_TARGET=	enough
TEST_TARGET=	check		# fail if USER == root directory owner
INSTALL_TARGET=	install-no-doc

REPLACE_INTERPRETER+=	scheme
REPLACE.scheme.old=	.*/bin/env scheme-srfi-7
REPLACE.scheme.new=	${PREFIX}/bin/scheme-srfi-7
REPLACE_FILES.scheme=	build/scheme48-config.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
SUBST_CLASSES+=		pthr
SUBST_STAGE.pthr=	pre-configure
SUBST_FILES.pthr=	configure
SUBST_MESSAGE.pthr=	Hardcoding -pthread in CFLAGS and LDFLAGS
SUBST_SED.pthr=		-e 's,pthreads_done=\"no\",pthreads_done=\"yes\"; CFLAGS=\"$$CFLAGS -pthread\"; LDFLAGS=\"$$LDFLAGS -pthread\",'
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# -O2 needs more than 2GB memory, just disabling value propagation
# results in segmentation faults during build.
CFLAGS+= -O0
.endif

post-install:
	cd ${WRKSRC}/doc/html && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/html/
	${INSTALL_MAN} ${WRKSRC}/doc/manual.ps ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/
	${INSTALL_MAN} ${WRKSRC}/doc/manual.pdf ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/

.include "../../devel/sysexits/buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
