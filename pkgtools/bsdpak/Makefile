# $NetBSD: Makefile,v 1.4 2002/12/24 18:55:40 wiz Exp $

DISTNAME=	bsdpak-0.51
CATEGORIES=	pkgtools
MASTER_SITES=	http://www.oddbox.org/projects/bsdpak/dists/

MAINTAINER=	collver1@attbi.com
HOMEPAGE=	http://www.oddbox.org/projects/bsdpak/index.php
COMMENT=	BSD package management utility

USE_PERL5=	yes

do-build:
	${SED} -e 's:/usr/bin/perl:${PERL5}:' \
		< ${WRKSRC}/bsdpak.pl \
		> ${WRKSRC}/bsdpak

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsdpak ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
