# $NetBSD: Makefile,v 1.9 2013/05/31 12:40:46 wiz Exp $

DISTNAME=	Term-Cap-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Cap/
COMMENT=	Perl termcap interface
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=	auto/Term/Cap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
