# $NetBSD: Makefile,v 1.15 2020/04/23 07:31:30 adam Exp $

DISTNAME=	colordiff-1.0.19
CATEGORIES=	devel
MASTER_SITES=	https://www.colordiff.org/

MAINTAINER=	rhansen@bbn.com
HOMEPAGE=	https://www.colordiff.org/
COMMENT=	Colour-highlighted 'diff' output
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	# none
USE_TOOLS=	perl:run
REPLACE_PERL=	colordiff.pl

CONF_FILES=	${EGDIR}/colordiffrc ${PKG_SYSCONFDIR}/colordiffrc
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

do-build:
	sed -e 's%/etc%${PKG_SYSCONFDIR}%g' '${WRKSRC}/colordiff.pl' \
		> '${WRKSRC}/colordiff.tmp'
	mv '${WRKSRC}/colordiff.tmp' '${WRKSRC}/colordiff'

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
