# $NetBSD: Makefile,v 1.12 2019/06/30 20:16:15 nia Exp $

DISTNAME=	Mail-Alias-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-Alias
COMMENT=	Perl 5 module to manipulate mail alias files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Mail/Alias/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
