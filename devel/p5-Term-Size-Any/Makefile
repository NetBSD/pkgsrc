# $NetBSD: Makefile,v 1.12 2023/07/06 09:40:08 wiz Exp $

DISTNAME=	Term-Size-Any-0.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-Size-Any
COMMENT=	Perl extension for retrieving terminal size
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Term-Size-Perl-[0-9]*:../../devel/p5-Term-Size-Perl

PERL5_PACKLIST=		auto/Term/Size/Any/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
