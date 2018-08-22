# $NetBSD: Makefile,v 1.18 2018/08/22 09:44:41 wiz Exp $

DISTNAME=	Term-Cap-1.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Cap/
COMMENT=	Perl termcap interface
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Term/Cap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
