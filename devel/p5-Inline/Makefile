# $NetBSD: Makefile,v 1.44 2019/08/11 13:19:41 wiz Exp $
#

DISTNAME=	Inline-0.83
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Inline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Inline
COMMENT=	Perl5 module for writing Perl subroutines in other languages
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=2.09}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Parse-RecDescent>=1.80:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1

PERL5_PACKLIST=		auto/Inline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
