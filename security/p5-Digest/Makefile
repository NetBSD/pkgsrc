# $NetBSD: Makefile,v 1.2 2003/12/16 22:32:47 heinz Exp $
#

DISTNAME=	Digest-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5dig
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest/
COMMENT=	Perl5 base class for Digest:: modules

DEPENDS+=	p5-MIME-Base64>=2.18:../../converters/p5-MIME-Base64

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
