# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 21:17:06 adrianp Exp $
#

DISTNAME=	Net-LMTP-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~lhoward/${DISTNAME}/
COMMENT=	Local Mail Transfer Protocol Client

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/LMTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
