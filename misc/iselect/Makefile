# $NetBSD: Makefile,v 1.21 2008/01/04 07:12:30 obache Exp $
#

DISTNAME=		iselect-1.2.0
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.ossp.org/pkg/tool/iselect/ \
			ftp://ftp.ntua.gr/pub/utils/ossp/tool/iselect/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ossp.org/pkg/tool/iselect/
COMMENT=		Curses based Interactive Selection Tool

GNU_CONFIGURE=		yes

post-configure:
	${TOUCH} ${WRKSRC}/config_ac.h.in

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
