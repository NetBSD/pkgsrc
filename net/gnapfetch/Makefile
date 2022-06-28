# $NetBSD: Makefile,v 1.22 2022/06/28 11:35:00 wiz Exp $

DISTNAME=	gnapfetch-0.3
PKGREVISION=	10
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
