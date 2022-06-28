# $NetBSD: Makefile,v 1.18 2022/06/28 11:32:34 wiz Exp $

DISTNAME=	IO-Capture-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Capture
COMMENT=	Perl modules to capture output to stdout and stderr

PERL5_PACKLIST=	auto/IO/Capture/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
