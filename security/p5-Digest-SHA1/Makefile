# $NetBSD: Makefile,v 1.32 2013/05/31 12:41:56 wiz Exp $

DISTNAME=	Digest-SHA1-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5sh2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-SHA1/
COMMENT=	Perl5 module for SHA1
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		{perl>=5.7.1,p5-Digest>=1.00}:../../security/p5-Digest

CONFLICTS+=		p5-Digest-MD5<=2.12

PERL5_PACKLIST=		auto/Digest/SHA1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
