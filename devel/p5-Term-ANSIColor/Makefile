# $NetBSD: Makefile,v 1.14 2014/10/09 14:06:27 wiz Exp $

DISTNAME=	Term-ANSIColor-4.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RR/RRA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ANSIColor/
COMMENT=	Perl termcap interface
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Term/ANSIColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
