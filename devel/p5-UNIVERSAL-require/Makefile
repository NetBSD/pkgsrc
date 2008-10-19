# $NetBSD: Makefile,v 1.5 2008/10/19 19:18:09 he Exp $

DISTNAME=	UNIVERSAL-require-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHWERN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-require/
COMMENT=	Perl module to require() from a variable

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/UNIVERSAL/require/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
