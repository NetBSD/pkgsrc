# $NetBSD: Makefile,v 1.22 2006/07/19 19:14:38 jlam Exp $

DISTNAME=		libPropList-0.10.1
PKGNAME=		libproplist-0.10.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/libs/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNUstep/OPENSTEP property lists compatibility library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		lex

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libproplist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
