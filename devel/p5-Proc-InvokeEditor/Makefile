# $NetBSD: Makefile,v 1.15 2017/09/17 12:58:35 wiz Exp $
#

DISTNAME=	Proc-InvokeEditor-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-InvokeEditor/
COMMENT=	Perl 5 module for starting a text editor
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Proc/InvokeEditor/.packlist

DEPENDS+=	p5-Carp-Assert>=0.11:../../devel/p5-Carp-Assert

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
