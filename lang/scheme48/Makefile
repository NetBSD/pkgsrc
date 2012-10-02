# $NetBSD: Makefile,v 1.35 2012/10/02 20:11:53 asau Exp $

DISTNAME=		scheme48-1.8
CATEGORIES=		lang
MASTER_SITES=		http://s48.org/1.8/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://s48.org/
COMMENT=		The Scheme Underground implementation of R5RS

NOT_FOR_PLATFORM=	*-*-alpha	# *severe* problems.  Bus error, alignment

MAKE_JOBS_SAFE=		no

# bin/scheme-r5rs
CONFLICTS+=		gambc-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS=		gmake
BUILD_TARGET=		enough
TEST_TARGET=		check		# fail if USER == root directory owner

MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}/man1

REPLACE_INTERPRETER+=	scheme
REPLACE.scheme.old=	.*/bin/env scheme-srfi-7
REPLACE.scheme.new=	${PREFIX}/bin/scheme-srfi-7
REPLACE_FILES.scheme=	build/scheme48-config.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "DragonFly"
SUBST_CLASSES+= 	pthr
SUBST_STAGE.pthr=	post-patch
SUBST_FILES.pthr=	configure
SUBST_MESSAGE.pthr=	Hardcoding -pthread in CFLAGS and LDFLAGS
SUBST_SED.pthr= 	-e 's,pthreads_done=\"no\",pthreads_done=\"yes\"; CFLAGS=\"$$CFLAGS -pthread\"; LDFLAGS=\"$$LDFLAGS -pthread\",'
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.txt *.ps \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/* \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}/html

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
