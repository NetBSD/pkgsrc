# $NetBSD: Makefile,v 1.1.1.1 2008/07/14 09:25:19 abs Exp $

DISTNAME=	Module-Find-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Find/
COMMENT=	Lets you find and use modules in categories

DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
DEPENDS+=	p5-PathTools>=0:../../devel/p5-PathTools

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Find/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
