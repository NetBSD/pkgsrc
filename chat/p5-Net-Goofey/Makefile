# $NetBSD: Makefile,v 1.2 2002/10/20 17:46:01 seb Exp $
#

DISTNAME=	Net-Goofey-1.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	http://tertius.net.au/~gossamer/code/Net-Goofey/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://tertius.net.au/~gossamer/code/
COMMENT=	perl module for communicating with a Goofey server

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Goofey/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
