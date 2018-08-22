# $NetBSD: Makefile,v 1.31 2018/08/22 09:44:14 wiz Exp $
#

DISTNAME=	Memoize-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.plover.com/Memoize/
COMMENT=	Transparently speed up functions by caching return values
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Memoize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
