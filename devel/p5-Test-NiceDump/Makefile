# $NetBSD: Makefile,v 1.2 2020/08/31 18:09:05 wiz Exp $

DISTNAME=	Test-NiceDump-1.0.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/D/DA/DAKKAR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/D/DA/DAKKAR/
COMMENT=	Let's have a nice and human readable dump of our objects!
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/NiceDump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
