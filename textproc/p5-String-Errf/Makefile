# $NetBSD: Makefile,v 1.1 2012/07/05 11:16:46 sno Exp $
#

DISTNAME=		String-Errf-0.006
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/String-Errf/
COMMENT=		Perl 5 module providing a simple string formatter
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-String-Formatter>=0.102081:../../textproc/p5-String-Formatter
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	{perl>=5.10.1,p5-Time-Piece-[0-9]*}:../../time/p5-Time-Piece

BUILD_DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
BUILD_DEPENDS+=	p5-JSON>=2.0:../../converters/p5-JSON
BUILD_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
# autodie is in core since 5.10

PERL5_PACKLIST=		auto/String/Errf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
