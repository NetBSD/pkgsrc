# $NetBSD: Makefile,v 1.1.1.1 2000/03/11 06:01:55 wiz Exp $
#

DISTNAME=	snobol-0.99.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.snobol4.com/ \
		ftp://alpha.gnu.org/budne/snobol/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://people.ne.mediaone.net/philbudne/snobol.html

ALL_TARGET=	it

USE_CONFIGURE=	NO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsnobol4 ${PREFIX}/bin/snobol4
	${INSTALL_MAN} ${WRKSRC}/doc/snobol4.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/lib/snobol4
	cd ${WRKSRC} && ${INSTALL_DATA} snolib.a snolib/bq.sno \
		${PREFIX}/lib/snobol4
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snobol4
	cd ${WRKSRC}/doc && ${INSTALL_DATA} load.doc design.doc \
		${PREFIX}/share/doc/snobol4

.include "../../mk/bsd.pkg.mk"
