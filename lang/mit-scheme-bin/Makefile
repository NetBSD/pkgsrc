# $NetBSD: Makefile,v 1.10 2024/03/01 06:34:45 kim Exp $
#

DISTNAME=		mit-scheme-7.7.1-ix86-gnu-linux
PKGNAME=		mit-scheme-bin-7.7.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=mit-scheme/stable.pkg/7.7.1/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/mit-scheme/
COMMENT=		MIT/GNU Scheme (Linux binary)

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin lib libexec

USE_TOOLS+=	pax

do-build:
	${SED} "s!@PREFIX@!${PREFIX}!g" ${FILESDIR}/scheme > ${WRKSRC}/scheme
	${SED} "s!@PREFIX@!${PREFIX}!g" ${FILESDIR}/bchscheme \
		> ${WRKSRC}/bchscheme

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bchscheme ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scheme ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bchscheme ${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/bin/scheme ${DESTDIR}${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/mit-scheme
	cd ${WRKSRC}/lib && pax -rw mit-scheme ${DESTDIR}${PREFIX}/lib
	${RMDIR} ${DESTDIR}${PREFIX}/lib/mit-scheme/lib

.include "../../mk/bsd.pkg.mk"
