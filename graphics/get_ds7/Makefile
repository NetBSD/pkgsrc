# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:57 jlam Exp $
#

DISTNAME=	get_ds7_1.2.4
PKGNAME=	get_ds7-1.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.yk.rim.or.jp/~mamo/Computer/DS-7/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.yk.rim.or.jp/~mamo/Computer/DS-7/index-e.html
COMMENT=	Read pictures from a FUJIFILM DS-7(DS series) digital camera

USE_PERL5=	# defined

WRKSRC=		${WRKDIR}/ds-7_1.2.4
DECOMPRESS_CMD=	${CAT}
NO_BUILD=	# defined

DOCDIR=		${PREFIX}/share/doc/get_ds7

INSTALLATION_DIRS=	bin

post-patch:
	${SED}	-e "s,/usr/bin/perl,${PERL5}," \
		<${WRKSRC}/get_ds7 >${WRKSRC}/get_ds7.exe

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_DATA} ${WRKSRC}/ds7_lib.pm ${PERL5_SITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/get_ds7.exe ${PREFIX}/bin/get_ds7
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/README.english ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
