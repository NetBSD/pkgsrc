# $NetBSD: Makefile,v 1.16 2004/01/20 12:23:57 agc Exp $
#

DISTNAME=	cdpack-1.5
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# This doesn't create readable manual pages. "mandoc" should be added
# to zoularis.
NROFF=		nroff -man
.else
NROFF=		nroff -mandoc
.endif

do-build:
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@progver@;${PKGVERSION};g' ${FILESDIR}/cdpack.sh > \
		${WRKDIR}/cdpack
	${CHMOD} 755 ${WRKDIR}/cdpack
	${NROFF} ${FILESDIR}/cdpack.1 > ${WRKSRC}/cdpack.0

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cdpack ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/cdgen.awk ${PREFIX}/libexec
	${INSTALL_MAN} ${FILESDIR}/cdpack.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cdpack.0 ${PREFIX}/man/cat1

.include "../../mk/bsd.pkg.mk"
