# $NetBSD: Makefile,v 1.1.1.1 2007/07/19 23:35:04 seb Exp $
#

DISTNAME=	Config-Std-v0.0.4
PKGNAME=	p5-Config-Std-0.0.4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Std/
COMMENT=	Perl 5 module providing a simple configuration-file system

DEPENDS+=	p5-Class-Std-[0-9]*:../../devel/p5-Class-Std
DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/Std/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
