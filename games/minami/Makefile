# $NetBSD: Makefile,v 1.23 2020/08/31 18:09:34 wiz Exp $
#

DISTNAME=	minami-1.0.2
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.guru.gr.jp/pub/minami/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.guru.gr.jp/~issei/minami/
COMMENT=	Text adventure

USE_TOOLS+=	perl:run
REPLACE_PERL=	gen_act gen_dun gen_itm gen_scn minflag

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minami ${DESTDIR}${PREFIX}/bin

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
