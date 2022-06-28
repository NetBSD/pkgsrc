# $NetBSD: Makefile,v 1.17 2022/06/28 11:34:51 wiz Exp $

DISTNAME=		Mac-PropertyList-1.502
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Work with Mac plists at a low level
HOMEPAGE=		https://metacpan.org/release/Mac-PropertyList
LICENSE=		artistic-2.0

DEPENDS+=		p5-XML-Entities-[0-9]*:../../textproc/p5-XML-Entities

PERL5_PACKLIST=		auto/Mac/PropertyList/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
