# $NetBSD: Makefile,v 1.8 2009/03/10 17:59:46 sno Exp $
#

DISTNAME=	Perl-Critic-1.098
PKGNAME=	p5-${DISTNAME}
#PKGNAME=	p5-${DISTNAME:C/0[0-9][0-9]$/.&/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl-Critic/
COMMENT=	Perl 5 module providing a static Perl source code analysis engine

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-B-Keywords>=1.05:../../devel/p5-B-Keywords
DEPENDS+=	p5-Config-Tiny>=2:../../devel/p5-Config-Tiny
DEPENDS+=	p5-Exception-Class>=1.23:../../devel/p5-Exception-Class
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Module-Pluggable>=3.1:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-PPI>=1.203:../../devel/p5-PPI
DEPENDS+=	p5-Readonly>=1.03:../../devel/p5-Readonly
DEPENDS+=	p5-String-Format>=1.13:../../devel/p5-String-Format
DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

.include "options.mk"

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Perl/Critic/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
