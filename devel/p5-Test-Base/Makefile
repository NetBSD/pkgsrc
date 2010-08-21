# $NetBSD: Makefile,v 1.6 2010/08/21 16:34:31 seb Exp $
#

DISTNAME=	Test-Base-0.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Base/
COMMENT=	Perl 5 module providing a data driven testing framework
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Base/.packlist

DEPENDS+=	p5-Spiffy>=0.30:../../devel/p5-Spiffy
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
