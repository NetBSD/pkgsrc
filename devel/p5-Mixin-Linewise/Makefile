# $NetBSD: Makefile,v 1.1.1.1 2009/01/28 22:06:14 seb Exp $
#

DISTNAME=	Mixin-Linewise-0.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mixin-Linewise/
COMMENT=	Perl 5 linewise readers and writers for strings and filenames

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Mixin/Linewise/.packlist

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Sub-Exporter>=0.900:../../devel/p5-Sub-Exporter

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
