# $NetBSD: Makefile,v 1.1.1.1 2004/01/01 04:06:34 wiz Exp $
#

DISTNAME=		dccserver-0.4
CATEGORIES=		chat
MASTER_SITES=		http://www.nih.at/dccserver/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.nih.at/dccserver/
COMMENT=		Standalone replacement for the mIRC /dccserver command

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/dccserver
	${INSTALL_DATA} ${WRKSRC}/contrib/dccsend.pl ${PREFIX}/share/dccserver

.include "../../mk/bsd.pkg.mk"
