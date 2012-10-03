# $NetBSD: Makefile,v 1.5 2012/10/03 21:55:39 wiz Exp $

DISTNAME=	Term-ShellUI-0.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ShellUI/
COMMENT=	Fully-featured shell-like command line environment for Perl
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Term/ShellUI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
