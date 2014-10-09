# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:27 wiz Exp $
#

DISTNAME=	String-PerlIdentifier-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-PerlIdentifier/
COMMENT=	Generate a random name for a Perl variable
#LICENSE=	${PERL_LICENSE}

PERL5_PACKLIST=	auto/String/PerlIdentifier/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
