# $NetBSD: Makefile,v 1.11 2017/06/05 14:23:38 ryoon Exp $
#

DISTNAME=	Template-Plugin-Handy-0.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-Handy/
COMMENT=	Handy virtual methods for Template Toolkit
LICENSE=	gnu-gpl-v2 # OR artistic

USE_LANGUAGES=		# empty

DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-Template-Plugin-VMethods-[0-9]*:../../devel/p5-Template-Plugin-VMethods

PERL5_PACKLIST=		auto/Template/Plugin/Handy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
