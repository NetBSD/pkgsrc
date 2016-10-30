# $NetBSD: Makefile,v 1.20 2016/10/30 05:10:10 mef Exp $

DISTNAME=	Term-ANSIColor-4.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ANSIColor/
COMMENT=	Perl termcap interface
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Term/ANSIColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
