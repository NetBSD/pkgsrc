# $NetBSD: Makefile,v 1.116 2001/11/29 01:56:37 hubertf Exp $
#

DISTNAME=	pkglint-3.13
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Verifier for NetBSD packages and complete pkgsrc tree

DEPENDS+=	digest-2001*:../../pkgtools/digest

USE_PERL5=	YES

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

PKGSRCDIR?=	${.CURDIR}/../..
MAKE_ENV=	PKGSRCDIR=${PKGSRCDIR}

DISTVER=	${DISTNAME:S/pkglint-//}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# This doesn't create readable manual pages. "mandoc" should be added
# to zoularis.
NROFF=		nroff -man
.else
NROFF=		nroff -mandoc
.endif

do-build:
.for FILE in pkglint lintpkgsrc plist-clash
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		< ${FILESDIR}/${FILE}.pl 		\
		> ${WRKSRC}/${FILE}
.endfor
.for FILE in pkglint lintpkgsrc
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${FILESDIR}/${FILE}.1			\
		> ${WRKSRC}/${FILE}.1
	${NROFF} ${WRKSRC}/${FILE}.1 >${WRKSRC}/${FILE}.0
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkglint ${PREFIX}/bin/pkglint
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc ${PREFIX}/bin/lintpkgsrc
	${INSTALL_SCRIPT} ${WRKSRC}/plist-clash ${PREFIX}/bin/plist-clash
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${WRKSRC}/lintpkgsrc.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${PREFIX}/man/cat1
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
