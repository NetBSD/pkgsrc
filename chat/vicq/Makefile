# $NetBSD: Makefile,v 1.2 2002/03/19 16:04:05 itojun Exp $

DISTNAME=	vicq-0.4
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
	(cd ${WRKSRC}; perl ./install.pl --prefix=${PREFIX})
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq

.include "../../mk/bsd.pkg.mk"
