# $NetBSD: Makefile,v 1.8 1999/03/10 08:24:16 agc Exp $
#

DISTNAME=		pkglint-1.69
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

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${FILESDIR}/pkglint.pl 		\
		> ${WRKSRC}/pkglint
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${FILESDIR}/lintpkgsrc.sh		\
		> ${WRKSRC}/lintpkgsrc
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${FILESDIR}/plist-clash.pl		\
		> ${WRKSRC}/plist-clash
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${FILESDIR}/pkglint.1			\
		> ${WRKSRC}/pkglint.1
	nroff -mandoc ${WRKSRC}/pkglint.1 >${WRKSRC}/pkglint.0

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkglint ${PREFIX}/bin/pkglint
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc ${PREFIX}/bin/lintpkgsrc
	${INSTALL_SCRIPT} ${WRKSRC}/plist-clash ${PREFIX}/bin/plist-clash
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${PREFIX}/man/cat1

.include "../../mk/bsd.pkg.mk"
