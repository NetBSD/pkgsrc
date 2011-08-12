# $NetBSD: Makefile,v 1.6 2011/08/12 06:29:11 adam Exp $

DISTNAME=	Data-Pageset-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Pageset/
COMMENT=	Page numbering and page sets
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Data-Page>=2.00:../../devel/p5-Data-Page

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Pageset/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
