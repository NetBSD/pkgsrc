# $NetBSD: Makefile,v 1.4 2018/11/16 13:02:45 bsiegert Exp $

DISTNAME=	Alien-Hunspell-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/P/PL/PLICEASE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~plicease/Alien-Hunspell/
COMMENT=	Perl5 module providing hunspell
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build
DEPENDS+=	p5-HTML-LinkExtractor-[0-9]*:../../www/p5-HTML-LinkExtractor
DEPENDS+=	p5-Sort-Versions-[0-9]*:../../devel/p5-Sort-Versions
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL

PERL5_PACKLIST=         auto/Alien/Hunspell/.packlist
USE_TOOLS+=	pkg-config

.include "../../textproc/hunspell/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
