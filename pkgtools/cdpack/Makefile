# $NetBSD: Makefile,v 1.19 2005/06/17 03:50:29 jlam Exp $
#

DISTNAME=	cdpack-1.5
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	Utility to create multi-cd binary package collections

# for mkisofs
DEPENDS+=	cdrecord-[0-9]*:../../sysutils/cdrecord

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_CONFIGURE=   yes

INSTALLATION_DIRS=	bin libexec man/man1

do-build:
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@progver@;${PKGVERSION};g' ${FILESDIR}/cdpack.sh > \
		${WRKDIR}/cdpack
	${CHMOD} 755 ${WRKDIR}/cdpack

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cdpack ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/cdgen.awk ${PREFIX}/libexec
	${INSTALL_MAN} ${FILESDIR}/cdpack.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
