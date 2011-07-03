# $NetBSD: Makefile,v 1.33 2011/07/03 12:40:20 jym Exp $

DISTNAME=		scheme48-1.8
CATEGORIES=		lang
MASTER_SITES=		http://s48.org/1.8/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://s48.org/
COMMENT=		The Scheme Underground's implementation of R5RS

NOT_FOR_PLATFORM=	*-*-alpha	# *severe* problems.  Bus error, alignment

PKG_DESTDIR_SUPPORT=	user-destdir
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
