# $NetBSD: Makefile,v 1.6 2012/10/03 21:55:32 wiz Exp $
#

DISTNAME=	Regexp-MatchContext-0.0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Regexp-MatchContext/
COMMENT=	Perl 5 module prodiving replacements for regexp related variables

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

# Ignore warning about the supposedly missing prerequisite Tie::StdScalar.
# It's there, have faith, run 'make test'!

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Regexp/MatchContext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
