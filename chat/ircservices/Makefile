# $NetBSD: Makefile,v 1.2 2003/04/11 17:31:29 salo Exp $
#

DISTNAME=	ircservices-5.0.16
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.esper.net/ircservices/ \
		ftp://ftp.esper.net/ircservices/old/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.ircservices.za.net/
COMMENT=	Services for IRC networks

HAS_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS=	-prefix ${PREFIX}

.include "../../mk/bsd.pkg.mk"
