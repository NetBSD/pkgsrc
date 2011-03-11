# $NetBSD: Makefile,v 1.6 2011/03/11 10:38:14 zafer Exp $
#

DISTNAME=	blackened-1.7.1
CATEGORIES=	chat
MASTER_SITES=	#ftp://ftp.blackened.com/pub/irc/blackened/
# newer version at http://freebsd.aeternal.net/ports/blackened-1.8.1.tar.gz

MAINTAINER=	carneous@carneous.net
HOMEPAGE=	http://www.blackened.com/blackened/
COMMENT=	The Blackened IRC client

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ircII-[0-9]*

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
