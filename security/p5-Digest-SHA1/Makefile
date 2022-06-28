# $NetBSD: Makefile,v 1.45 2022/06/28 11:35:47 wiz Exp $

DISTNAME=	Digest-SHA1-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-SHA1
COMMENT=	Perl5 module for SHA1
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.7.1,p5-Digest>=1.00}:../../security/p5-Digest

CONFLICTS+=		p5-Digest-MD5<=2.12

PERL5_PACKLIST=		auto/Digest/SHA1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
