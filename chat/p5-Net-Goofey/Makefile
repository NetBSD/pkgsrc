# $NetBSD: Makefile,v 1.4 2003/07/21 16:34:34 martti Exp $
#

DISTNAME=	Net-Goofey-1.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	http://tertius.net.au/~gossamer/code/Net-Goofey/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://tertius.net.au/~gossamer/code/
COMMENT=	Perl module for communicating with a Goofey server

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Goofey/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
