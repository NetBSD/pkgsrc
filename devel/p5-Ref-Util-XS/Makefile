# $NetBSD: Makefile,v 1.2 2017/06/05 14:23:32 ryoon Exp $

DISTNAME=	Ref-Util-XS-0.116
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Ref/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Ref-Util-XS/
COMMENT=	XS implementation for Ref::Util
LICENSE=	mit

PERL5_PACKLIST=		auto/Ref/Util/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
