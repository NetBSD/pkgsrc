# $NetBSD: Makefile,v 1.45 2024/05/27 13:34:35 cheusov Exp $
#

DISTNAME=	mk-configure-0.39.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight but powerful replacement for GNU autotools
LICENSE=	modified-bsd

DEPENDS+=	bmake-[0-9]*:../../devel/bmake

USE_LANGUAGES=		c c++
USE_TOOLS=		makeinfo pax

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

MAKE_PROGRAM=		${PREFIX}/bin/bmake

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} \
			SYSCONFDIR=${PKG_SYSCONFDIR} \
			BMAKE=${PREFIX}/bin/bmake \
			USE_INSTALL=mkc_install \
			USE_AWK=${AWK:Q} \
			USE_ID=${ID:Q}

PLIST_SRC+=		${WRKDIR}/PLIST-addon
PLIST_SRC+=		PLIST

EGDIR=			share/examples/mk-configure
INSTALLATION_DIRS=	${EGDIR}

TEST_TARGET=		test

post-build:
	set -e; cd ${WRKSRC}/mk; \
	${FIND} . -name 'mkc_imp.cc_*' -o -name 'mkc_imp.cxx_*' | \
		${SED} "s;^\([.]/\)*;share/mk-configure/mk/;g" > ${WRKDIR}/PLIST-addon

post-install:
	cd ${WRKSRC}/examples && ${PAX} -wr * ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/presentation/*.pdf \
		${DESTDIR}${PREFIX}/share/doc/mk-configure

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS_SKIP=	*/foobar.in */hello_world3.in */prog1.awk.in

.if ${OPSYS} != NetBSD && ${OPSYS} != FreeBSD && ${OPSYS} != OpenBSD && ${OPSYS} != DragonFly && ${OPSYS} != MirBSD
# non-BSD system
DEPENDS+=	bmkdep-[0-9]*:../../devel/bmkdep
.endif

.include "../../mk/bsd.pkg.mk"
