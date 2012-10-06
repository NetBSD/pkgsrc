# $NetBSD: Makefile,v 1.14 2012/10/06 11:54:47 asau Exp $
#

DISTNAME=	minami-1.0.2
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.guru.gr.jp/pub/minami/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.guru.gr.jp/~issei/minami/
COMMENT=	Text adventure

USE_TOOLS+=	perl:run
REPLACE_PERL=	gen_act gen_dun gen_itm gen_scn minflag

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minami ${DESTDIR}${PREFIX}/bin

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
