# $NetBSD: Makefile,v 1.4 2003/03/28 21:19:11 wiz Exp $
#

DISTNAME=	jamjar-0.6
CATEGORIES=	archivers
MASTER_SITES=	ftp://wonka.acunia.com/pub/wonka/

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the jar archiver

BUILD_DEPENDS+=	acunia-jam>=1.0:../../devel/acunia-jam

USE_BUILDLINK2=	YES
WRKSRC=		${WRKDIR}/jamjar

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
