# $NetBSD: Makefile,v 1.14 2021/05/24 19:53:09 wiz Exp $

DISTNAME=		Mac-PropertyList-1.413
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Work with Mac plists at a low level
HOMEPAGE=		https://metacpan.org/release/Mac-PropertyList
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-XML-Entities-[0-9]*:../../textproc/p5-XML-Entities

PERL5_PACKLIST=		auto/Mac/PropertyList/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
