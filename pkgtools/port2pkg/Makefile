# $NetBSD: Makefile,v 1.14 2002/01/01 17:01:01 wiz Exp $
#

DISTNAME=	port2pkg-1.10
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	Convert from a FreeBSD port to a NetBSD package

DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint

USE_PERL5=	YES

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
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
	${SED} -e 's|$${GTAR}|${GTAR}|g' ${FILESDIR}/port2pkg.pl \
		> ${WRKSRC}/port2pkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/port2pkg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/port2pkg.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${FILESDIR}/port2pkg.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
