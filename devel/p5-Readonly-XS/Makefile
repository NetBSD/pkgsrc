# $NetBSD: Makefile,v 1.5 2009/02/10 19:46:51 he Exp $
#

DISTNAME=	Readonly-XS-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Readonly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Readonly-XS/
COMMENT=	Perl 5 companion module to the Readonly module

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Readonly>=1.02:../../devel/p5-Readonly

PERL5_PACKLIST=	auto/Readonly/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
