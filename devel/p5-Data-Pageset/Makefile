# $NetBSD: Makefile,v 1.4 2010/02/15 14:38:54 sno Exp $

DISTNAME=	Data-Pageset-1.06
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Pageset/
COMMENT=	Page numbering and page sets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Page>=2.00:../../devel/p5-Data-Page

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/Pageset/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
