# $NetBSD: Makefile,v 1.22 2022/06/28 11:31:29 wiz Exp $

DISTNAME=	Rose-DBx-Garden-0.193
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Rose-DBx-Garden
COMMENT=	Bootstrap Rose::DB::Object and Rose::HTML::Form classes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-File-Slurp-Tiny-[0-9]*:../../devel/p5-File-Slurp-Tiny
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Rose-DB-Object-[0-9]*:../../databases/p5-Rose-DB-Object
DEPENDS+=	p5-Rose-DBx-TestDB-[0-9]*:../../databases/p5-Rose-DBx-TestDB
DEPENDS+=	p5-Rose-HTML-Objects-[0-9]*:../../www/p5-Rose-HTML-Objects
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Autocomplete-[0-9]*:../../www/p5-Rose-HTMLx-Form-Field-Autocomplete
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Boolean>=0.01:../../www/p5-Rose-HTMLx-Form-Field-Boolean
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Serial-[0-9]*:../../www/p5-Rose-HTMLx-Form-Field-Serial

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/DBx/Garden/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
