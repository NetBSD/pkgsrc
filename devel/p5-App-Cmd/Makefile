# $NetBSD: Makefile,v 1.3 2008/07/21 11:59:33 rhaen Exp $
#

DISTNAME=	App-Cmd-0.013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-Cmd/
COMMENT=	Perl 5 module to write command line apps with less suffering

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Getopt-Long-Descriptive>=0.06:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Sub-Install-[0-9]*:../../devel/p5-Sub-Install

PERL5_PACKLIST=	auto/App/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
