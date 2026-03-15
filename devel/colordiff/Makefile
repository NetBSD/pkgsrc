# $NetBSD: Makefile,v 1.23 2026/03/15 18:19:48 wiz Exp $

DISTNAME=	colordiff-1.0.22
CATEGORIES=	devel
MASTER_SITES=	https://www.colordiff.org/
# PR 60080, remove on next update
DIST_SUBDIR=	colordiff-1.0.22-repack

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.colordiff.org/
COMMENT=	Colour-highlighted 'diff' output
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	# none
USE_TOOLS=	perl:run
REPLACE_PERL=	colordiff.pl

CONF_FILES=	${EGDIR}/colordiffrc ${PKG_SYSCONFDIR}/colordiffrc
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

do-build:
	${SED} -e 's%/etc%${PKG_SYSCONFDIR}%g' '${WRKSRC}/colordiff.pl' \
		> '${WRKSRC}/colordiff.tmp'
	${MV} '${WRKSRC}/colordiff.tmp' '${WRKSRC}/colordiff'

do-install:
	${INSTALL_SCRIPT_DIR} '${DESTDIR}${PREFIX}/bin'
	${INSTALL_SCRIPT} '${WRKSRC}/colordiff' '${DESTDIR}${PREFIX}/bin'
	${INSTALL_SCRIPT} '${WRKSRC}/cdiff.sh' '${DESTDIR}${PREFIX}/bin/cdiff'

	${INSTALL_MAN_DIR} '${DESTDIR}${PREFIX}/${PKGMANDIR}/man1'
	${INSTALL_MAN} '${WRKSRC}/colordiff.1' \
		'${DESTDIR}${PREFIX}/${PKGMANDIR}/man1'
	${INSTALL_MAN} '${WRKSRC}/cdiff.1' \
		'${DESTDIR}${PREFIX}/${PKGMANDIR}/man1'

	${INSTALL_DATA_DIR} '${DESTDIR}${EGDIR}'
	${INSTALL_DATA} '${WRKSRC}/colordiffrc' '${DESTDIR}${EGDIR}'

.include "../../mk/bsd.pkg.mk"
