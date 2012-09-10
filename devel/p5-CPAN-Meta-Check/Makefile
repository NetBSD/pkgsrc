# $NetBSD: Makefile,v 1.1 2012/09/10 12:21:37 sno Exp $

DISTNAME=	CPAN-Meta-Check-0.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Meta-Check/
COMMENT=	Perl module to verify requirements in a CPAN::Meta object
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.16.0,p5-CPAN-Meta>=2.120920}:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-CPAN-Meta-Requirements>=2.122:../../devel/p5-CPAN-Meta-Requirements

BUILD_DEPENDS+= p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences

PERL5_PACKLIST=		auto/CPAN/Meta/Check/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
