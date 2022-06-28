# $NetBSD: Makefile,v 1.20 2022/06/28 11:33:09 wiz Exp $
#

DISTNAME=	Regexp-MatchContext-0.0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Regexp-MatchContext
COMMENT=	Perl 5 module prodiving replacements for regexp related variables

#DEPENDS+=	{perl>=5.9.0,p5-version-[0-9]*}:../../devel/p5-version

# Ignore warning about the supposedly missing prerequisite Tie::StdScalar.
# It's there, have faith, run 'make test'!

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Regexp/MatchContext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
