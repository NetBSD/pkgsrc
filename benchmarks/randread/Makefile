# $NetBSD: Makefile,v 1.11 2011/02/03 14:15:12 obache Exp $
#

DISTNAME=	randread-0.2
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=randread/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://randread.sourceforge.net/
COMMENT=	Program to help benchmark random disk read performance
LICENSE=	public-domain

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	randread
WRKSRC=		${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/randread ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
TEST_TARGET=	test
BUILDLINK_DEPMETHOD.check=	build
.include "../../devel/check/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
