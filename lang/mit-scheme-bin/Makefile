# $NetBSD: Makefile,v 1.1.1.1 2006/04/13 21:37:29 wiz Exp $
#

DISTNAME=		mit-scheme-7.7.1-ix86-gnu-linux
PKGNAME=		mit-scheme-bin-7.7.1
CATEGORIES=		lang
MASTER_SITES=		http://ftp.gnu.org/gnu/mit-scheme/stable.pkg/7.7.1/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/mit-scheme/
COMMENT=		MIT/GNU Scheme (Linux binary)

DEPENDS+=		suse_base>=6.0:../../emulators/${SUSE_DIR_PREFIX}_base

WRKSRC=		${WRKDIR}

CHECK_SHLIBS=	NO
SHLIB_HANDLING=	NO

INSTALLATION_DIRS=	bin

do-build:
	${SED} "s!@PREFIX@!${PREFIX}!g" ${FILESDIR}/scheme > ${WRKSRC}/scheme
	${SED} "s!@PREFIX@!${PREFIX}!g" ${FILESDIR}/bchscheme \
		> ${WRKSRC}/bchscheme

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bchscheme ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scheme ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bchscheme ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/scheme ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mit-scheme
	cd ${WRKSRC}/lib && ${PAX} -rw mit-scheme ${PREFIX}/lib
	${RMDIR} ${PREFIX}/lib/mit-scheme/lib

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
