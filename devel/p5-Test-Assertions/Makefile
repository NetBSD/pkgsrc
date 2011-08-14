# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:39 obache Exp $
#

DISTNAME=	Test-Assertions-1.054
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Assertions/
COMMENT=	Perl 5 module prodiving building blocks for unit and runtime testing

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl	# for test target
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Assertions/.packlist

DEPENDS+=	p5-Log-Trace-[0-9]*:../../devel/p5-Log-Trace

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
