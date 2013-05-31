# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:44 wiz Exp $
#

DISTNAME=	String-PerlIdentifier-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-PerlIdentifier/
COMMENT=	Generate a random name for a Perl variable
#LICENSE=	${PERL_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/String/PerlIdentifier/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
