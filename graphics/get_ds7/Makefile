# $NetBSD: Makefile,v 1.1.1.1 1999/11/23 04:20:23 hubertf Exp $
#

DISTNAME=	get_ds7_1.2.4
PKGNAME=	get_ds7-1.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.yk.rim.or.jp/~mamo/Computer/DS-7/
EXTRACT_SUFX=	.tar

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.yk.rim.or.jp/~mamo/Computer/DS-7/index-e.html

DECOMPRESS_CMD=	${CAT}
WRKSRC=		${WRKDIR}/ds-7_1.2.4
USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
		${SED} \
			-e 's,@LOCALBASE@,${LOCALBASE},' \
			<${WRKSRC}/get_ds7 >${WRKSRC}/get_ds7.exe

do-install:
		${INSTALL_DATA} ${WRKSRC}/ds7_lib.pm ${LOCALBASE}/lib/perl5/site_perl
		${INSTALL_SCRIPT} ${WRKSRC}/get_ds7.exe ${PREFIX}/bin/get_ds7
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/get_ds7
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/get_ds7
		${INSTALL_MAN} ${WRKSRC}/README.english ${PREFIX}/share/doc/get_ds7

.include "../../mk/bsd.pkg.mk"
