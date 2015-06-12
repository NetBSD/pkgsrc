# $NetBSD: Makefile,v 1.5 2015/06/12 10:50:36 wiz Exp $

DISTNAME=		Mac-PropertyList-1.41
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Work with Mac plists at a low level
HOMEPAGE=		http://search.cpan.org/~bdfoy/Mac-PropertyList/
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Mac/PropertyList/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
