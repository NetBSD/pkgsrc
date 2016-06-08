# $NetBSD: Makefile,v 1.10 2016/06/08 19:23:31 wiz Exp $
#

DISTNAME=	String-PerlIdentifier-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-PerlIdentifier/
COMMENT=	Generate a random name for a Perl variable
#LICENSE=	${PERL_LICENSE}

PERL5_PACKLIST=	auto/String/PerlIdentifier/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
