# $NetBSD: Makefile,v 1.9 2016/06/08 19:23:03 wiz Exp $
#

DISTNAME=	IO-Pipeline-0.009002
PKGNAME=	p5-IO-Pipeline-0.9.2
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Pipeline/
COMMENT=	Perl 5 module providing map and grep for filehandles, unix pipe style
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Pipeline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
