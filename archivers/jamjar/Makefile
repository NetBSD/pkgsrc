# $NetBSD: Makefile,v 1.20 2014/10/09 14:05:52 wiz Exp $
#

DISTNAME=	jamjar-0.7.1
CATEGORIES=	archivers
MASTER_SITES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the jar archiver

BUILD_DEPENDS+=	acunia-jam>=1.0:../../devel/acunia-jam

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
