# $NetBSD: Makefile,v 1.74 2001/01/19 21:16:51 tron Exp $
#

DISTNAME=		pkglint-2.34
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt

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
# This doesn't create readable manual pages. "mandoc" should be added
# to zoularis.
NROFF=		nroff -man
.else
NROFF=		nroff -mandoc
.endif

do-build:
.for file in pkglint lintpkgsrc plist-clash
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${FILESDIR}/${file}.pl 		\
		> ${WRKSRC}/${file}
.endfor
.for file in pkglint lintpkgsrc
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${FILESDIR}/${file}.1			\
		> ${WRKSRC}/${file}.1
	${NROFF} ${WRKSRC}/${file}.1 >${WRKSRC}/${file}.0
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
