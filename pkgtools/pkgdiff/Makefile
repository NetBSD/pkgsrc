# $NetBSD: Makefile,v 1.17 2001/09/27 23:18:35 jlam Exp $
#

DISTNAME=		pkgdiff-0.101
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=		Tools to ease creating and maintaining patches for pkgsrc

USE_PERL5=		YES

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

PKGSRCDIR?=	${.CURDIR}/../..
MAKE_ENV=	PKGSRCDIR=${PKGSRCDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=	groff-[0-9]*:../../textproc/groff
NROFF=		gnroff
.else
NROFF=		nroff
.endif

do-build:
.for FILE in mkpatches patchdiff
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@MAKE@|${MAKE}|g'			\
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
