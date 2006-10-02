# $NetBSD: Makefile,v 1.10 2006/10/02 21:16:20 rillig Exp $
#

DISTNAME=	Net-Goofey-1.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	chat perl5
MASTER_SITES=	http://tertius.net.au/~gossamer/code/Net-Goofey/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://tertius.net.au/~gossamer/code/
COMMENT=	Perl module for communicating with a Goofey server

PERL5_PACKLIST=		auto/Net/Goofey/.packlist

# Requires the user to enter a username/password
INTERACTIVE_STAGE=	test

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
