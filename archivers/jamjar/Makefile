# $NetBSD: Makefile,v 1.23 2023/06/06 12:40:15 riastradh Exp $
#

DISTNAME=	jamjar-0.7.1
CATEGORIES=	archivers
MASTER_SITES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://wonka.acunia.com/
COMMENT=	Acunia version of the jar archiver

TOOL_DEPENDS+=	acunia-jam>=1.0:../../devel/acunia-jam

WRKSRC=		${WRKDIR}/jamjar

JAM_COMMAND=	\
	cd ${WRKSRC} &&							\
		${SETENV} ${MAKE_ENV}					\
		${LOCALBASE}/bin/jam					\
			-sPREFIX="${DESTDIR}${PREFIX}"			\
			-sCFLAGS="${CFLAGS}"

do-build:
	${JAM_COMMAND}

do-install:
	${JAM_COMMAND} install

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
