# $NetBSD: Makefile,v 1.31 2020/01/22 10:53:58 cheusov Exp $
#

DISTNAME=	mk-configure-0.33.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight but powerful replacement for GNU autotools
LICENSE=	modified-bsd

DEPENDS+=	bmake-[0-9]*:../../devel/bmake

USE_LANGUAGES=		c

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

MAKE_PROGRAM=		${PREFIX}/bin/bmake

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} \
			SYSCONFDIR=${PKG_SYSCONFDIR} \
			BMAKE=${PREFIX}/bin/bmake \
			MKC_AWK=${AWK:Q}

AUTO_MKDIRS=		yes

EGDIR=			share/examples/mk-configure

TEST_TARGET=		test

post-install:
	${CP} -Rp ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/presentation/*.pdf ${DESTDIR}${PREFIX}/share/doc/mk-configure

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS_SKIP=	*/foobar.in */hello_world3.in */prog1.awk.in

.if ${OPSYS} != NetBSD && ${OPSYS} != FreeBSD && ${OPSYS} != OpenBSD && ${OPSYS} != DragonFly && ${OPSYS} != MirBSD
DEPENDS+=	bmkdep-[0-9]*:../../devel/bmkdep
.endif

.include "../../mk/bsd.pkg.mk"
