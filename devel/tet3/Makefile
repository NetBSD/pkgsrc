# $NetBSD: Makefile,v 1.1.1.1 2003/06/17 17:39:03 agc Exp $

DISTNAME=	tet3.3h-unsup.src
PKGNAME=	tet3-3.3h
CATEGORIES=	devel
MASTER_SITES=	http://tetworks.opengroup.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://tetworks.opengroup.org/
COMMENT=	The Open Group test harness

WRKSRC=		${WRKDIR}/src
HAS_CONFIGURE=	yes
REPLACE_PERL=	yes
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
