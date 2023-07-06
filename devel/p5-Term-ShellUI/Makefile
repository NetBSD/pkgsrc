# $NetBSD: Makefile,v 1.19 2023/07/06 09:40:08 wiz Exp $

DISTNAME=	Term-ShellUI-0.92
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ShellUI
COMMENT=	Fully-featured shell-like command line environment for Perl
LICENSE=	mit

PERL5_PACKLIST=		auto/Term/ShellUI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
