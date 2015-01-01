# $NetBSD: Makefile,v 1.15 2015/01/01 09:22:23 dholland Exp $
#

DISTNAME=	randread-0.2
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=randread/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://randread.sourceforge.net/
COMMENT=	Program to help benchmark random disk read performance
LICENSE=	public-domain

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
