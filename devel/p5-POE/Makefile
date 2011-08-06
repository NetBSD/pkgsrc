# $NetBSD: Makefile,v 1.19 2011/08/06 13:24:20 adam Exp $

DISTNAME=	POE-1.312
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://poe.perl.org/
#HOMEPAGE=	http://search.cpan.org/dist/POE/
COMMENT=	Perl Object Environment
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress
DEPENDS+=	p5-Curses>=1.08:../../devel/p5-Curses
DEPENDS+=	p5-Event>=1.00:../../devel/p5-Event
DEPENDS+=	p5-IO-tty>=1.08:../../devel/p5-IO-Tty
DEPENDS+=	p5-IO>=1.2301:../../devel/p5-IO
DEPENDS+=	p5-POE-Test-Loops>=1.030:../../devel/p5-POE-Test-Loops
DEPENDS+=	p5-Socket6>=0.14:../../net/p5-Socket6
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Term-Cap>=1.09:../../devel/p5-Term-Cap
DEPENDS+=	p5-Time-HiRes>=1.59:../../time/p5-Time-HiRes
DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_PARAMS+=	--default
PERL5_PACKLIST=	auto/POE/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
