# $NetBSD: Makefile,v 1.7 2006/03/04 21:30:48 jlam Exp $

DISTNAME=	Pod-Escapes-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Escapes/
COMMENT=	Perl module for decoding Pod E<...> sequences

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Pod/Escapes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
