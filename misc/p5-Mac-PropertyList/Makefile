# $NetBSD: Makefile,v 1.7 2017/06/05 14:24:15 ryoon Exp $

DISTNAME=		Mac-PropertyList-1.41
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Work with Mac plists at a low level
HOMEPAGE=		http://search.cpan.org/~bdfoy/Mac-PropertyList/
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Mac/PropertyList/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
