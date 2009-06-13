# $NetBSD: Makefile,v 1.3 2009/06/13 06:46:46 rillig Exp $

DISTNAME=	ANSIColor-2.00
PKGNAME=	p5-Term-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ANSIColor/
COMMENT=	Perl termcap interface

PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=	auto/Term/ANSIColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

