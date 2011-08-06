# $NetBSD: Makefile,v 1.5 2011/08/06 14:41:11 adam Exp $

DISTNAME=	Unicode-MapUTF8-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-MapUTF8/
COMMENT=	Provides conversions for arbitrary character sets and UTF8
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String
DEPENDS+=	p5-Unicode-Map8-[0-9]*:../../converters/p5-Unicode-Map8
DEPENDS+=	p5-Unicode-Map-[0-9]*:../../converters/p5-Unicode-Map
DEPENDS+=	p5-Jcode-[0-9]*:../../converters/p5-Jcode

PERL5_PACKLIST=		auto/Unicode/MapUTF8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
