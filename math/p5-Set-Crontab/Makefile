# $NetBSD: Makefile,v 1.8 2010/08/21 16:35:14 seb Exp $

DISTNAME=	Set-Crontab-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Crontab/
COMMENT=	Perl module to parse crontab(5)-like lists of integers

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Set/Crontab/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
