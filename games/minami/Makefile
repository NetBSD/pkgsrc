# $NetBSD: Makefile,v 1.2 2001/11/28 14:25:49 jlam Exp $
#

DISTNAME=	minami-1.0.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.guru.gr.jp/pub/minami/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.guru.gr.jp/~issei/minami/
COMMENT=	Text adventure

USE_BUILDLINK_ONLY=	YES
REPLACE_PERL=		gen_act gen_dun gen_itm gen_scn minflag

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minami ${PREFIX}/bin

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
