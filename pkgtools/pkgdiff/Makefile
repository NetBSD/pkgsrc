# $NetBSD: Makefile,v 1.24.2.2 2002/06/21 23:05:34 jlam Exp $
#

DISTNAME=	pkgdiff-0.105
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Tools to ease creating and maintaining patches for pkgsrc

PERL5_REQD=	5.6.0

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

USE_BUILDLINK2=	yes

MAKE_ENV=	PKGSRCDIR=${_PKGSRCDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
BUILD_DEPENDS+=	groff-[0-9]*:../../textproc/groff
NROFF=		gnroff
DIFF?=		gdiff
.else
NROFF=		nroff
DIFF?=		diff
.endif

do-build:
.for FILE in mkpatches patchdiff
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@MAKE@|${MAKE}|g'			\
		< ${FILESDIR}/${FILE}.pl 		\
		> ${WRKSRC}/${FILE}
.endfor
	${SED} -e 's|@DIFF@|${DIFF}|g'			\
		< ${FILESDIR}/pkgdiff			\
		> ${WRKSRC}/pkgdiff
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

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
