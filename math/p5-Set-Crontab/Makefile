# $NetBSD: Makefile,v 1.10 2011/08/14 13:38:24 obache Exp $

DISTNAME=	Set-Crontab-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Crontab/
COMMENT=	Perl module to parse crontab(5)-like lists of integers
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Set/Crontab/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
