# $NetBSD: Makefile,v 1.1 2013/11/22 10:43:37 wiz Exp $

DISTNAME=	Term-Size-Any-0.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Size-Any/
COMMENT=	Perl extension for retrieving terminal size
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Term-Size-Perl-[0-9]*:../../devel/p5-Term-Size-Perl

PERL5_PACKLIST=		auto/Term/Size/Any/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
