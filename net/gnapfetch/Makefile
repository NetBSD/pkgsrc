# $NetBSD: Makefile,v 1.1 2000/08/08 08:18:44 jlam Exp $

DISTNAME=	gnapfetch-0.3
CATEGORIES=	net
MASTER_SITES=	http://entropy.atlantic.net/gnapfetch/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://entropy.atlantic.net/gnapfetch/

USE_PERL5=	# defined
PERL=		${LOCALBASE}/bin/perl

do-build:
	${SED} -e "s,/usr/bin/perl,${PERL},g" < ${WRKSRC}/gnapfetch \
		> ${WRKDIR}/gnapfetch

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gnapfetch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnapfetch
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gnapfetch

.include "../../mk/bsd.pkg.mk"
