# $NetBSD: Makefile,v 1.13 2001/05/24 17:02:44 abs Exp $
#

DISTNAME=		pkgdiff-0.100
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Documentation/netbsd/Packages.txt
COMMENT=		Tools to ease creating and maintaining patches for pkgsrc

USE_PERL5=		YES

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

PKGSRCDIR?=	${.CURDIR}/../..
MAKE_ENV=	PKGSRCDIR=${PKGSRCDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
NROFF=		gnroff
.else
NROFF=		nroff
.endif

do-build:
.for FILE in mkpatches patchdiff
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		< ${FILESDIR}/${FILE}.pl 		\
		> ${WRKSRC}/${FILE}
.endfor
	${CP} ${FILESDIR}/pkgdiff ${WRKSRC}
	${CP} ${FILESDIR}/pkgvi ${WRKSRC}
.for FILE in mkpatches patchdiff pkgdiff pkgvi
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		< ${FILESDIR}/${FILE}.1			\
		> ${WRKSRC}/${FILE}.1
	${NROFF} -mandoc ${WRKSRC}/${FILE}.1 >${WRKSRC}/${FILE}.0
.endfor

do-install:
.for FILE in mkpatches patchdiff pkgdiff pkgvi
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${FILE}.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${WRKSRC}/${FILE}.1 ${PREFIX}/man/man1
.endfor

.include "../../mk/bsd.pkg.mk"
