# $NetBSD: Makefile,v 1.3 1999/09/03 04:37:36 sakamoto Exp $
#

DISTNAME=	port2pkg-1.2
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@netbsd.org

RUN_DEPENDS+=	pkglint:../../pkgtools/pkglint

USE_PERL5=	YES

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
NROFF=		gnroff
.else
NROFF=		nroff
.endif

do-build:
	${NROFF} -mandoc ${FILESDIR}/port2pkg.1 >${WRKSRC}/port2pkg.0

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/port2pkg.pl ${PREFIX}/bin/port2pkg
	${INSTALL_MAN} ${WRKSRC}/port2pkg.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${FILESDIR}/port2pkg.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
