# $NetBSD: Makefile,v 1.1.1.1 2001/04/22 07:53:00 kei Exp $
#

DISTNAME=	minami-1.0.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.guru.gr.jp/pub/minami/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.guru.gr.jp/~issei/minami/
COMMENT=	Text adventure

USE_PERL5=	# empty

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/minami ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
