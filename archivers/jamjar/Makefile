# $NetBSD: Makefile,v 1.11 2004/10/27 16:48:56 wiz Exp $
#

DISTNAME=	jamjar-0.6
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.acunia.com/wonka/

MAINTAINER=	skrll@NetBSD.org
HOMEPAGE=	http://www.acunia.com/wonka/
COMMENT=	Acunia version of the jar archiver

BUILD_DEPENDS+=	acunia-jam>=1.0:../../devel/acunia-jam

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/jamjar
USE_BUILDLINK3=	YES

JAM_COMMAND=	\
	cd ${WRKSRC} &&							\
		${SETENV} ${MAKE_ENV}					\
		${LOCALBASE}/bin/jam					\
			-sPREFIX="${PREFIX}"				\
			-sCFLAGS="${CFLAGS}"

do-build:
	${JAM_COMMAND}

do-install:
	${JAM_COMMAND} install

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
