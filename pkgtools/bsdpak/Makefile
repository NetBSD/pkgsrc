# $NetBSD: Makefile,v 1.1.1.1 2000/12/09 00:44:04 wiz Exp $

DISTNAME=	bsdpak-0.40
CATEGORIES=	pkgtools
MASTER_SITES=	http://www.oddbox.org/projects/bsdpak/dists/

MAINTAINER=	collver@softhome.net
HOMEPAGE=	http://www.oddbox.org/projects/bsdpak/index.php

USE_PERL5=	yes

do-build:
	${SED} -e 's:/usr/bin/perl:${PERL5}:' \
		< ${WRKSRC}/bsdpak.pl \
		> ${WRKSRC}/bsdpak

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsdpak ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
