# $NetBSD: Makefile,v 1.2 2000/08/26 05:12:18 jlam Exp $
#

DISTNAME=	get_ds7_1.2.4
PKGNAME=	get_ds7-1.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.yk.rim.or.jp/~mamo/Computer/DS-7/
EXTRACT_SUFX=	.tar

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.yk.rim.or.jp/~mamo/Computer/DS-7/index-e.html

USE_PERL5=	# defined

DECOMPRESS_CMD=	${CAT}
WRKSRC=		${WRKDIR}/ds-7_1.2.4
NO_BUILD=	# defined

DOCDIR=		${PREFIX}/share/doc/get_ds7

post-patch:
	${SED}	-e 's,@LOCALBASE@,${LOCALBASE},' \
		<${WRKSRC}/get_ds7 >${WRKSRC}/get_ds7.exe

do-install:
	${INSTALL_DATA} ${WRKSRC}/ds7_lib.pm ${LOCALBASE}/lib/perl5/site_perl
	${INSTALL_SCRIPT} ${WRKSRC}/get_ds7.exe ${PREFIX}/bin/get_ds7
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/README.english ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
