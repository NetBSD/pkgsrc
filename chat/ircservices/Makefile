# $NetBSD: Makefile,v 1.8 2004/04/11 05:53:08 snj Exp $
#

DISTNAME=	ircservices-5.0.16
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.esper.net/ircservices/ \
		ftp://ftp.esper.net/ircservices/old/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.ircservices.za.net/
COMMENT=	Services for IRC networks

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

USE_GNU_TOOLS+=	grep
USE_PERL5=	build

CONFIGURE_ARGS=	-prefix ${PREFIX}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
