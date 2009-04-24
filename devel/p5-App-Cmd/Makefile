# $NetBSD: Makefile,v 1.7 2009/04/24 08:17:24 sno Exp $
#

DISTNAME=	App-Cmd-0.203
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-Cmd/
COMMENT=	Perl 5 module to write command line apps with less suffering

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Getopt-Long-Descriptive>=0.06:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	{perl>=5.10,p5-Module-Pluggable-[0-9]*}:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Sub-Install-[0-9]*:../../devel/p5-Sub-Install
DEPENDS+=	p5-Sub-Exporter>=0.975:../../devel/p5-Sub-Exporter

BUILD_DEPENDS+=	p5-IO-TieCombine>=1:../../devel/p5-IO-TieCombine

PERL5_PACKLIST=	auto/App/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
