# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 08:43:05 abs Exp $

DISTNAME=	Rose-DBx-Garden-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Rose::DBx::Garden
COMMENT=	Bootstrap Rose::DB::Object and Rose::HTML::Form classes

DEPENDS+=	p5-Rose-DB-Object>=0:../../databases/p5-Rose-DB-Object
DEPENDS+=	p5-Rose-DBx-TestDB>=0:../../databases/p5-Rose-DBx-TestDB
DEPENDS+=	p5-File-Slurp>=0:../../devel/p5-File-Slurp
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump
DEPENDS+=	p5-Rose-HTML-Objects>=0:../../www/p5-Rose-HTML-Objects
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Autocomplete>=0:../../www/p5-Rose-HTMLx-Form-Field-Autocomplete
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Boolean>=0.01:../../www/p5-Rose-HTMLx-Form-Field-Boolean

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/DBx/Garden/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
