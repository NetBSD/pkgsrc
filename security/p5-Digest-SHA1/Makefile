# $NetBSD: Makefile,v 1.38 2016/06/08 19:24:23 wiz Exp $

DISTNAME=	Digest-SHA1-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-SHA1/
COMMENT=	Perl5 module for SHA1
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.7.1,p5-Digest>=1.00}:../../security/p5-Digest

CONFLICTS+=		p5-Digest-MD5<=2.12

PERL5_PACKLIST=		auto/Digest/SHA1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
