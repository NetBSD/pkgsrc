# $NetBSD: Makefile,v 1.11 2021/05/24 19:51:39 wiz Exp $

DISTNAME=	Term-Size-Perl-0.031
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-Size-Perl
COMMENT=	Perl extension for retrieving terminal size in perl
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Term/Size/Perl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
