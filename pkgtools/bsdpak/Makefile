# $NetBSD: Makefile,v 1.3 2001/10/16 09:17:08 agc Exp $

DISTNAME=	bsdpak-0.51
CATEGORIES=	pkgtools
MASTER_SITES=	http://www.oddbox.org/projects/bsdpak/dists/

MAINTAINER=	collver@linuxfreemail.com
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
