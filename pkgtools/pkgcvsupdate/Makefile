# $NetBSD: Makefile,v 1.1.1.1 2001/11/29 14:13:27 seb Exp $

DISTNAME=	pkgcvsupdate-0.1
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Tool to ease updating package source files from CVS

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=	groff-[0-9]*:../../textproc/groff
NROFF=		gnroff
DIFF?=		gdiff
.else
NROFF=		nroff
DIFF?=		diff
.endif

do-build:
	${SED} 					\
	  -e 's|@BASENAME@|${BASENAME}|g'	\
	  -e 's|@DIRNAME@|${DIRNAME}|g'		\
	  -e 's|@GREP@|${GREP}|g'		\
	  -e 's|@LS@|${LS}|g'			\
	  -e 's|@MAKE@|${MAKE}|g'		\
	  -e 's|@TEST@|${TEST}|g'		\
		< ${FILESDIR}/pkgcvsupdate.sh 	\
		> ${WRKSRC}/pkgcvsupdate
	${NROFF} -mandoc ${FILESDIR}/pkgcvsupdate.1 >${WRKSRC}/pkgcvsupdate.0

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgcvsupdate ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkgcvsupdate.0 ${DESTDIR}${PREFIX}/man/cat1
	${INSTALL_MAN} ${FILESDIR}/pkgcvsupdate.1 ${DESTDIR}${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
