# $NetBSD: Makefile,v 1.3 2003/07/22 18:09:01 agc Exp $

DISTNAME=	tet3.3h-unsup.src
PKGNAME=	tet3-3.3h
CATEGORIES=	devel
MASTER_SITES=	http://tetworks.opengroup.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tetworks.opengroup.org/
COMMENT=	The Open Group test harness

WRKSRC=		${WRKDIR}/src
HAS_CONFIGURE=	yes
REPLACE_PERL=	../contrib/suite/src/common.pl ../contrib/NTperldemo/ts/tc1.pl
REPLACE_PERL+=	../contrib/NTperldemo/ts/tc2.pl ../contrib/NTperldemo/ts/tc3.pl
REPLACE_PERL+=	../contrib/tetreport/TetJournal.pl ../contrib/tetreport/TetReports.pl
REPLACE_PERL+=	../contrib/tetreport/tetreport.pl ../contrib/templates/perl-api.pl
REPLACE_PERL+=	perl/api.pl perl/make_tcm.pl perl/template.pl
MAKEFILE=	makefile

INTERACTIVE_STAGE=	fetch

do-configure:
	cd ${WRKSRC}/.. && ${CHMOD} 755 configure && ./configure -t inet

post-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/tet3
	${INSTALL_PROGRAM_DIR} ${PREFIX}/tet3/bin
	cd ${WRKSRC}/../bin && ${PAX} -rwpe . ${PREFIX}/tet3/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/tet3/lib
	cd ${WRKSRC}/../lib && ${PAX} -rwpe . ${PREFIX}/tet3/lib

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
