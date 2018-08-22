# $NetBSD: Makefile,v 1.33 2018/08/22 09:43:41 wiz Exp $

DISTNAME=	Capture-Tiny-0.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Capture-Tiny/
COMMENT=	Capture STDOUT and STDERR from Perl, XS or external programs
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/Capture/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
