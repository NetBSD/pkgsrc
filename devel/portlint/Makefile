# $NetBSD: Makefile,v 1.5 1998/08/07 22:25:34 tsarna Exp $
#

DISTNAME=		portlint-1.64
CATEGORIES=		devel
INFO_URL=		http://www.netbsd.org/Documentation/netbsd/Packages.txt
MASTER_SITES=		ftp://ftp.foretune.co.jp/pub/tools/portlint/
EXTRACT_SUFX=		.shar

MAINTAINER=		frueauf@netbsd.org

USE_PERL5=		YES

EXTRACT_CMD=		${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

NO_WRKSUBDIR=		yes
NO_CONFIGURE=		yes

MAKE_ENV=		PKGSRCDIR=${.CURDIR}/../..

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${WRKSRC}/portlint.pl 		\
		> ${WRKSRC}/portlint
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${WRKSRC}/lintpkgsrc.sh		\
		> ${WRKSRC}/lintpkgsrc
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@PORTSDIR@|${PKGSRCDIR}|g'	\
		< ${WRKSRC}/plist-clash.pl		\
		> ${WRKSRC}/plist-clash

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portlint ${PREFIX}/bin/portlint
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc ${PREFIX}/bin/lintpkgsrc
	${INSTALL_SCRIPT} ${WRKSRC}/plist-clash ${PREFIX}/bin/plist-clash
	${INSTALL_MAN} ${WRKSRC}/portlint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
