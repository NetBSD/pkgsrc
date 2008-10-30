# $NetBSD: Makefile,v 1.1.1.1 2008/10/30 23:01:47 he Exp $
#

DISTNAME=	Pod-Strip-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Strip/
COMMENT=	Perl5 module to remove POD from Perl code

DEPENDS+=	p5-Pod-Simple>=3.0:../../textproc/p5-Pod-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Pod/Strip/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
