# $NetBSD: Makefile,v 1.19 2023/07/06 09:39:25 wiz Exp $
#

DISTNAME=	Locale-Msgfmt-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Locale-Msgfmt
COMMENT=	Perl 5 module to compile .po files to .mo files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Locale/Msgfmt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
