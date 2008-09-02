# $NetBSD: Makefile,v 1.1.1.1 2008/09/02 23:09:20 seb Exp $
#

DISTNAME=	Test-Base-0.54
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Base/
COMMENT=	Perl 5 module providing a data driven testing framework

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Base/.packlist

DEPENDS+=	p5-Spiffy-[0-9]*:../../devel/p5-Spiffy

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
