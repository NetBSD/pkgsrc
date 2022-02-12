# $NetBSD: Makefile,v 1.19 2022/02/12 18:05:08 adam Exp $

DISTNAME=	colordiff-1.0.20
CATEGORIES=	devel
MASTER_SITES=	https://www.colordiff.org/

MAINTAINER=	pkgsrc-users@netbsd.org
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
