# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:03 tv Exp $
#

DISTNAME=		dccserver-0.4
CATEGORIES=		chat
MASTER_SITES=		http://www.nih.at/dccserver/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.nih.at/dccserver/
COMMENT=		Standalone replacement for the mIRC /dccserver command

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/dccserver
	${INSTALL_DATA} ${WRKSRC}/contrib/dccsend.pl ${PREFIX}/share/dccserver

.include "../../mk/bsd.pkg.mk"
