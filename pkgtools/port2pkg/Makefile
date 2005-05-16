# $NetBSD: Makefile,v 1.24 2005/05/16 01:15:32 jlam Exp $
#

DISTNAME=	port2pkg-1.11
PKGREVISION=	3
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	Convert from a FreeBSD port to a NetBSD package

DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint

WRKSRC=		${WRKDIR}
USE_PERL5=	YES

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	gtar

.include "../../mk/bsd.prefs.mk"

do-build:
.if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX"
	# the pre-generated man-pages are 'mandoc';  these OS need 'man'
	nroff -man ${FILESDIR}/port2pkg.1 >${WRKSRC}/port2pkg.0
.else
	${CP} ${FILESDIR}/port2pkg.0 ${WRKSRC}/port2pkg.0
.endif
	${SED} -e 's|$${GTAR}|${GTAR}|g' ${FILESDIR}/port2pkg.pl \
		> ${WRKSRC}/port2pkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/port2pkg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/port2pkg.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${FILESDIR}/port2pkg.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
