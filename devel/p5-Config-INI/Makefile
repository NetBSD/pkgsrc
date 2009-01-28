# $NetBSD: Makefile,v 1.1.1.1 2009/01/28 22:07:18 seb Exp $
#

DISTNAME=	Config-INI-0.014
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-INI/
COMMENT=	Perl 5 module to handle simple .ini-file format

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/INI/.packlist

DEPENDS+=	p5-Mixin-Linewise-[0-9]*:../../devel/p5-Mixin-Linewise

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
