# $NetBSD: Makefile,v 1.20 2006/10/04 21:49:19 wiz Exp $
#

DISTNAME=		iselect-1.2.0
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		http://www.ossp.org/pkg/tool/iselect/distrib/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ossp.org/pkg/tool/iselect/
COMMENT=		Curses based Interactive Selection Tool

GNU_CONFIGURE=		yes

post-configure:
	${TOUCH} ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
