# $NetBSD: Makefile,v 1.13 1999/07/08 09:46:08 agc Exp $
#

DISTNAME=		pkglint-1.73
CATEGORIES=		pkgtools devel
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Documentation/netbsd/Packages.txt

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
	${NROFF} -mandoc ${WRKSRC}/${file}.1 >${WRKSRC}/${file}.0
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
