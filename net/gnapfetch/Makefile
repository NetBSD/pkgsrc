# $NetBSD: Makefile,v 1.5 2003/07/21 17:10:40 martti Exp $

DISTNAME=	gnapfetch-0.3
CATEGORIES=	net
MASTER_SITES=	http://entropy.atlantic.net/gnapfetch/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://entropy.atlantic.net/gnapfetch/
COMMENT=	Update/maintain opennap servers for gnapster/TekNap

USE_PERL5=	# defined

do-build:
	${SED} -e "s,/usr/bin/perl,${PERL5},g" \
		< ${WRKSRC}/gnapfetch > ${WRKDIR}/gnapfetch

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gnapfetch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnapfetch
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gnapfetch

.include "../../mk/bsd.pkg.mk"
