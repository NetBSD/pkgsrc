# $NetBSD: Makefile,v 1.4 2003/05/25 21:03:25 jmc Exp $
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
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_PERL5=	build

CONFIGURE_ARGS=	-prefix ${PREFIX}

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
