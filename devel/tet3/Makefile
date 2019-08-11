# $NetBSD: Makefile,v 1.30 2019/08/11 13:20:52 wiz Exp $

DISTNAME=	tet3.7-unsup.src
PKGNAME=	tet3-3.7
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	http://tetworks.opengroup.org/tet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tetworks.opengroup.org/
COMMENT=	The Open Group test harness
LICENSE=	artistic

WRKSRC=		${WRKDIR}
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${SH}
CONFIGURE_ARGS+=	-t inet
BUILD_DIRS=		src

USE_LANGUAGES=	c c++
USE_TOOLS+=	pax perl:run ksh:run
REPLACE_PERL=	contrib/suite/src/common.pl contrib/NTperldemo/ts/tc1.pl
REPLACE_PERL+=	contrib/NTperldemo/ts/tc2.pl contrib/NTperldemo/ts/tc3.pl
REPLACE_PERL+=	contrib/tetreport/TetJournal.pl contrib/tetreport/TetReports.pl
REPLACE_PERL+=	contrib/tetreport/tetreport.pl contrib/templates/perl-api.pl
REPLACE_PERL+=	src/perl/api.pl
REPLACE_KSH+=	src/scripts/tet_start.sh
MAKE_FILE=	makefile

INSTALLATION_DIRS=	tet3/bin tet3/lib

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	java
.if ${OPSYS} == "SunOS"
PLIST.java=	yes
.endif

post-install:
	cd ${WRKSRC}/bin && pax -rwpp . ${DESTDIR}${PREFIX}/tet3/bin
	cd ${WRKSRC}/lib && pax -rwpp . ${DESTDIR}${PREFIX}/tet3/lib

PTHREAD_OPTS+=	native	# only native threads make sense
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
PKG_SKIP_REASON+=	"Native threads are needed for this package"
.endif

.include "../../mk/bsd.pkg.mk"
