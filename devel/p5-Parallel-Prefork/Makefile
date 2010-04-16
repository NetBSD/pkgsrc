# $NetBSD: Makefile,v 1.1.1.1 2010/04/16 03:55:42 seb Exp $
#

DISTNAME=	Parallel-Prefork-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/Parallel-Prefork/
COMMENT=	Perl 5 simple prefork server framework
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parallel/Prefork/.packlist

DEPENDS+=	p5-Class-Accessor>=0.31:../../devel/p5-Class-Accessor
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Proc-Wait3>=0.03:../../devel/p5-Proc-Wait3
DEPENDS+=	p5-Scope-Guard-[0-9]*:../../devel/p5-Scope-Guard

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
