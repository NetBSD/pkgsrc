# $NetBSD: Makefile,v 1.1 1998/04/25 13:23:35 frueauf Exp $
#

DISTNAME=		portlint-1.64
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.foretune.co.jp/pub/tools/portlint/
EXTRACT_SUFX=		.shar

MAINTAINER=		frueauf@netbsd.org

USE_PERL5=		YES

EXTRACT_CMD=		${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

NO_WRKSUBDIR=		yes
NO_CONFIGURE=		yes

MAN1=			portlint.1

do-build:
	${CAT} ${WRKSRC}/portlint.pl | \
		${SED} s/@PREFIX@/${PREFIX:S/\//\\\\\//g}/g | \
		${SED} s/@PORTSDIR@/${PORTSDIR:S/\//\\\\\//g}/g \
		> ${WRKSRC}/portlint
	${CAT} ${WRKSRC}/lintpkgsrc.sh | \
		${SED} s/@PREFIX@/${PREFIX:S/\//\\\\\//g}/g | \
		${SED} s/@PORTSDIR@/${PORTSDIR:S/\//\\\\\//g}/g \
		> ${WRKSRC}/lintpkgsrc
	${CAT} ${WRKSRC}/plist-clash.pl | \
		${SED} s/@PREFIX@/${PREFIX:S/\//\\\\\//g}/g | \
		${SED} s/@PORTSDIR@/${PORTSDIR:S/\//\\\\\//g}/g \
		> ${WRKSRC}/plist-clash

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portlint ${PREFIX}/bin/portlint
	${INSTALL_SCRIPT} ${WRKSRC}/lintpkgsrc ${PREFIX}/bin/lintpkgsrc
	${INSTALL_SCRIPT} ${WRKSRC}/plist-clash ${PREFIX}/bin/plist-clash
	${INSTALL_MAN} ${WRKSRC}/portlint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
