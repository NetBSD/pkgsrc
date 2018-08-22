# $NetBSD: Makefile,v 1.16 2018/08/22 09:46:49 wiz Exp $
#

DISTNAME=		Feed-Find-0.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/B/BT/BTROTT/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Feed-Find/
COMMENT=		Perl module to perform autodiscovery of syndication feeds
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--defaultdeps
PERL5_PACKLIST=		auto/Feed/Find/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
