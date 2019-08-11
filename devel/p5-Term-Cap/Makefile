# $NetBSD: Makefile,v 1.20 2019/08/11 13:20:25 wiz Exp $

DISTNAME=	Term-Cap-1.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-Cap
COMMENT=	Perl termcap interface
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Term/Cap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
