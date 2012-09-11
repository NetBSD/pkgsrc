# $NetBSD: Makefile,v 1.18 2012/09/11 19:46:55 asau Exp $
#

DISTNAME=	jamjar-0.7.1
CATEGORIES=	archivers
MASTER_SITES=	# none

MAINTAINER=	skrll@NetBSD.org
HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the jar archiver

BUILD_DEPENDS+=	acunia-jam>=1.0:../../devel/acunia-jam

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/jamjar

EVAL_PREFIX+=	ACUNIA_JAM_PREFIX=acunia-jam
JAM_COMMAND=	\
	cd ${WRKSRC} &&							\
		${SETENV} ${MAKE_ENV}					\
		${ACUNIA_JAM_PREFIX}/bin/jam				\
			-sPREFIX="${DESTDIR}${PREFIX}"			\
			-sCFLAGS="${CFLAGS}"

do-build:
	${JAM_COMMAND}

do-install:
	${JAM_COMMAND} install

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
