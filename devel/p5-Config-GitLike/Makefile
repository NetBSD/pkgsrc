# $NetBSD: Makefile,v 1.3 2010/08/21 16:33:27 seb Exp $
#

DISTNAME=	Config-GitLike-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-GitLike/
COMMENT=	Perl 5 module providing a git-compatible config file parser
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/GitLike/.packlist

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose

# For test target
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
