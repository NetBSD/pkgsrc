# $NetBSD: Makefile,v 1.7 2005/04/11 21:45:52 tv Exp $
#

DISTNAME=	minami-1.0.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.guru.gr.jp/pub/minami/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.guru.gr.jp/~issei/minami/
COMMENT=	Text adventure

REPLACE_PERL=	gen_act gen_dun gen_itm gen_scn minflag

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minami ${PREFIX}/bin

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
