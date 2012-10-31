# $NetBSD: Makefile,v 1.24 2012/10/31 11:17:19 asau Exp $

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

INSTALLATION_DIRS=	share/doc/libproplist

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
