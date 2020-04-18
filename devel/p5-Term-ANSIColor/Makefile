# $NetBSD: Makefile,v 1.25 2020/04/18 01:33:53 mef Exp $

DISTNAME=	Term-ANSIColor-5.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ANSIColor
COMMENT=	Perl termcap interface
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Term/ANSIColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
