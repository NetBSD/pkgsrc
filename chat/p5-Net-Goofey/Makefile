# $NetBSD: Makefile,v 1.11 2006/10/04 20:50:47 wiz Exp $
#

DISTNAME=	Net-Goofey-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	chat perl5
MASTER_SITES=	http://notdoneliving.net/code/Net-Goofey/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://notdoneliving.net/code/
COMMENT=	Perl module for communicating with a Goofey server

PERL5_PACKLIST=		auto/Net/Goofey/.packlist

# Requires the user to enter a username/password
INTERACTIVE_STAGE=	test

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
