# $NetBSD: Makefile,v 1.33 2020/03/30 14:10:55 cheusov Exp $
#

DISTNAME=	mk-configure-0.34.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight but powerful replacement for GNU autotools
LICENSE=	modified-bsd

DEPENDS+=	bmake-[0-9]*:../../devel/bmake

USE_LANGUAGES=		c c++

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

MAKE_PROGRAM=		${PREFIX}/bin/bmake

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} \
			SYSCONFDIR=${PKG_SYSCONFDIR} \
			BMAKE=${PREFIX}/bin/bmake \
			USE_AWK=${AWK:Q} \
			USE_ID=${ID:Q}

PLIST_SRC+=		${WRKDIR}/PLIST-addon
PLIST_SRC+=		PLIST

EGDIR=			share/examples/mk-configure
INSTALLATION_DIRS=	${EGDIR}

TEST_TARGET=		test

post-install:
	${CP} -Rp ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/presentation/*.pdf \
		${DESTDIR}${PREFIX}/share/doc/mk-configure
	${FIND} ${DESTDIR}${PREFIX}/share/mk-configure/mk | \
		grep -E 'mkc_imp.(cc|cxx)' | \
		${SED} 's;${DESTDIR}${PREFIX}/;;g' > ${WRKDIR}/PLIST-addon

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS_SKIP=	*/foobar.in */hello_world3.in */prog1.awk.in

.if ${OPSYS} != NetBSD && ${OPSYS} != FreeBSD && ${OPSYS} != OpenBSD && ${OPSYS} != DragonFly && ${OPSYS} != MirBSD
DEPENDS+=	bmkdep-[0-9]*:../../devel/bmkdep
.endif

.include "../../mk/bsd.pkg.mk"
