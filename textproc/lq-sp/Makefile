# $NetBSD: Makefile,v 1.1.1.1 2001/05/30 09:44:00 abs Exp $
#

DISTNAME=	lq-sp-1.3.4.5
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	Modified SP package

do-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.netbsd
	${SED} -e 's:@PREFIX@:${PREFIX}:'	\
	    < ${WRKSRC}/Makefile.netbsd		\
	    > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsgmls/lq-nsgmls ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
