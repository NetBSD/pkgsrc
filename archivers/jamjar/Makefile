# $NetBSD: Makefile,v 1.7 2004/01/20 12:07:06 agc Exp $
#

DISTNAME=	jamjar-0.6
CATEGORIES=	archivers
MASTER_SITES=	ftp://wonka.acunia.com/pub/wonka/

MAINTAINER=	skrll@NetBSD.org
HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the jar archiver

BUILD_DEPENDS+=	acunia-jam>=1.0:../../devel/acunia-jam

WRKSRC=		${WRKDIR}/jamjar
USE_BUILDLINK2=	YES

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

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
