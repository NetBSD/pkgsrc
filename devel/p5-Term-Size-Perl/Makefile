# $NetBSD: Makefile,v 1.1 2013/11/22 10:40:57 wiz Exp $

DISTNAME=	Term-Size-Perl-0.029
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Size-Perl/
COMMENT=	Perl extension for retrieving terminal size in perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Term/Size/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
