# $NetBSD: Makefile,v 1.3 2009/06/13 06:46:46 rillig Exp $

DISTNAME=	Term-Cap-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Cap/
COMMENT=	Perl termcap interface

PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=	auto/Term/Cap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

