# $NetBSD: Makefile,v 1.1.1.1 2011/12/12 03:57:11 hiramatsu Exp $

DISTNAME=	POEx-Types-1.100910
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NP/NPEREZ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POEx-Types/
COMMENT=	Exported Types for use within POEx modules
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/POEx/Types/.packlist

DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Structured-[0-9]*:../../devel/p5-MooseX-Types-Structured
DEPENDS+=	p5-POE-[0-9]*:../../devel/p5-POE

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
