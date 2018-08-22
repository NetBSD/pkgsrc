# $NetBSD: Makefile,v 1.13 2018/08/22 09:44:43 wiz Exp $

DISTNAME=	Term-ShellUI-0.92
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ShellUI/
COMMENT=	Fully-featured shell-like command line environment for Perl
LICENSE=	mit

PERL5_PACKLIST=		auto/Term/ShellUI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
