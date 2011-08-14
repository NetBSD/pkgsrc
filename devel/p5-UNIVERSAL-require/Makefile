# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:48 obache Exp $

DISTNAME=	UNIVERSAL-require-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHWERN/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-require/
COMMENT=	Perl module to require() from a variable
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/UNIVERSAL/require/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
