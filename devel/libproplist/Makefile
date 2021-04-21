# $NetBSD: Makefile,v 1.25 2021/04/21 08:35:04 wiz Exp $

DISTNAME=		libPropList-0.10.1
PKGNAME=		libproplist-0.10.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		# ftp://ftp.windowmaker.org/pub/libs/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNUstep/OPENSTEP property lists compatibility library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		lex

INSTALLATION_DIRS=	share/doc/libproplist

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/libproplist

.include "../../mk/bsd.pkg.mk"
