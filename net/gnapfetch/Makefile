# $NetBSD: Makefile,v 1.19 2019/08/11 13:22:09 wiz Exp $

DISTNAME=	gnapfetch-0.3
PKGREVISION=	7
CATEGORIES=	net
#MASTER_SITES=	http://entropy.atlantic.net/gnapfetch/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://entropy.atlantic.net/gnapfetch/
COMMENT=	Update/maintain opennap servers for gnapster/TekNap

USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	bin share/doc/gnapfetch

do-build:
	${SED} -e "s,/usr/bin/perl,${PERL5},g" \
		< ${WRKSRC}/gnapfetch > ${WRKDIR}/gnapfetch

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gnapfetch ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gnapfetch

.include "../../mk/bsd.pkg.mk"
