# $NetBSD: Makefile,v 1.33 2016/06/08 19:24:22 wiz Exp $

DISTNAME=	Digest-HMAC-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-HMAC/
COMMENT=	Perl5 module for HMAC
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.3,p5-Digest-SHA>=1.00}:../../security/p5-Digest-SHA
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=2.00}:../../security/p5-Digest-MD5

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Digest/HMAC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
