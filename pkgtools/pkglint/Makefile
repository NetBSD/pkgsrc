# $NetBSD: Makefile,v 1.168 2003/09/21 20:32:35 wiz Exp $
#

DISTNAME=	pkglint-3.61
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Verifier for NetBSD packages and complete pkgsrc tree

DEPENDS+=	digest>=20010101:../../pkgtools/digest

USE_PERL5=	YES

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

MAKE_ENV=	PKGSRCDIR=${_PKGSRCDIR:Q}

DISTVER=	${DISTNAME:S/pkglint-//}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# This doesn't create readable manual pages. "mandoc" should be added
# to zoularis.
NROFF=		nroff -man
.else
NROFF=		nroff -mandoc
.endif

do-extract:
	@${MKDIR} ${WRKSRC}/src
.for FILE in lintpkgsrc.1 lintpkgsrc.pl pkglint.1 pkglint.pl plist-clash.pl
	${CP} ${FILESDIR}/${FILE} ${WRKSRC}/src/${FILE}
.endfor

do-build:
.for FILE in pkglint lintpkgsrc plist-clash
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${_PKGSRCDIR}|g'	\
		-e 's|@DISTVER@|${DISTVER}|g'		\
		-e 's|@MAKE@|${MAKE}|g'			\
		< ${WRKSRC}/src/${FILE}.pl 		\
		> ${WRKSRC}/${FILE}
.endfor
.for FILE in pkglint lintpkgsrc
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${_PKGSRCDIR}|g'	\
		-e 's|@MAKE@|${MAKE}|g'			\
		< ${WRKSRC}/src/${FILE}.1		\
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
