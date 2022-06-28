# $NetBSD: Makefile,v 1.33 2022/06/28 11:31:20 wiz Exp $

DISTNAME=	Class-DBI-v3.0.17
PKGNAME=	p5-${DISTNAME:S:-v:-:}
PKGREVISION=	17
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TM/TMTM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-DBI
COMMENT=	Perl5 module for Simple Database Abstraction

DEPENDS+=	p5-Class-Accessor>=0.18:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Trigger>=0.07:../../devel/p5-Class-Trigger
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-Ima-DBI>=0.33:../../databases/p5-Ima-DBI
DEPENDS+=	p5-UNIVERSAL-moniker>=0.06:../../devel/p5-UNIVERSAL-moniker

PERL5_PACKLIST=	auto/Class/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
