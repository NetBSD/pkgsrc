# $NetBSD: Makefile,v 1.1.1.1 2009/04/20 19:40:56 seb Exp $
#

DISTNAME=	MooseX-InsideOut-0.102
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-InsideOut/
COMMENT=	Perl 5 module providing inside-out objects with Moose
#LICENSE=	artistic OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/InsideOut/.packlist

DEPENDS+=	p5-Class-MOP>=0.80:../../devel/p5-Class-MOP
DEPENDS+=	p5-Hash-Util-FieldHash-Compat-[0-9]*:../../devel/p5-Hash-Util-FieldHash-Compat
DEPENDS+=	p5-Moose>=0.73:../../devel/p5-Moose
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
