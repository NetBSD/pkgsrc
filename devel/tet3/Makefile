# $NetBSD: Makefile,v 1.14 2006/09/09 02:41:58 obache Exp $

DISTNAME=	tet3.7-unsup.src
PKGNAME=	tet3-3.7
CATEGORIES=	devel
MASTER_SITES=	http://tetworks.opengroup.org/tet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tetworks.opengroup.org/
COMMENT=	The Open Group test harness

WRKSRC=		${WRKDIR}
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${SH}
CONFIGURE_ARGS+=	-t inet
BUILD_DIRS=		src

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run
REPLACE_PERL=	contrib/suite/src/common.pl contrib/NTperldemo/ts/tc1.pl
REPLACE_PERL+=	contrib/NTperldemo/ts/tc2.pl contrib/NTperldemo/ts/tc3.pl
REPLACE_PERL+=	contrib/tetreport/TetJournal.pl contrib/tetreport/TetReports.pl
REPLACE_PERL+=	contrib/tetreport/tetreport.pl contrib/templates/perl-api.pl
REPLACE_PERL+=	src/perl/api.pl
MAKE_FILE=	makefile

post-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/tet3
	${INSTALL_PROGRAM_DIR} ${PREFIX}/tet3/bin
	cd ${WRKSRC}/bin && ${PAX} -rwpe . ${PREFIX}/tet3/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/tet3/lib
	cd ${WRKSRC}/lib && ${PAX} -rwpe . ${PREFIX}/tet3/lib

PTHREAD_OPTS+=	native	# only native threads make sense
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
PKG_SKIP_REASON+=	"Native threads are needed for this package"
.endif

.include "../../mk/bsd.pkg.mk"
