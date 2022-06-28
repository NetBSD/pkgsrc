# $NetBSD: Makefile,v 1.23 2022/06/28 11:36:15 wiz Exp $
#

DISTNAME=		Feed-Find-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/D/DA/DAVECROSS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Feed-Find
COMMENT=		Perl module to perform autodiscovery of syndication feeds
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--defaultdeps
PERL5_PACKLIST=		auto/Feed/Find/.packlist

#TEST_DEPENDS+=		p5-Test-LWP-UserAgent-[0-9]*:../../www/p5-Test-LWP-UserAgent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
