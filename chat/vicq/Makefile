# $NetBSD: Makefile,v 1.1.1.1 2001/12/30 11:37:47 zuntum Exp $

DISTNAME=	vicq-0.3
CATEGORIES=	chat
MASTER_SITES=	http://gonzo.kiev.ua/projects/vicq/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gonzo.kiev.ua/projects/vicq/
COMMENT=	simple icq client written in perl

WRKSRC=		${WRKDIR}/vicq

USE_PERL5=	YES
REPLACE_PERL=	${WRKSRC}/vicq
NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq
	${INSTALL_SCRIPT} ${WRKSRC}/vicq ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
