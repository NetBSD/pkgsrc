# $NetBSD: Makefile,v 1.10 2014/05/29 23:35:48 wiz Exp $

DISTNAME=	Data-Pageset-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Pageset/
COMMENT=	Page numbering and page sets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Page>=2.00:../../devel/p5-Data-Page

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Pageset/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
