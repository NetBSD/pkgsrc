# $NetBSD: Makefile,v 1.4.2.1 2002/06/30 06:24:19 jlam Exp $
#

DISTNAME=	lq-sp-1.3.4.7
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	Modified SP package

USE_BUILDLINK2=	YES

# doesn't build (LP64 bugs)
NOT_FOR_PLATFORM=	*-*-alpha

do-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.netbsd
	${SED} -e 's:@PREFIX@:${PREFIX}:'	\
	    < ${WRKSRC}/Makefile.netbsd		\
	    > ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsgmls/lq-nsgmls ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
