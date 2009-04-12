# $NetBSD: Makefile,v 1.5 2009/04/12 19:07:31 sno Exp $

DISTNAME=	NEXT-0.63
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NEXT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/NEXT/
COMMENT=	Provide a pseudo-class NEXT (et al) that allows method redispatch
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/NEXT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
