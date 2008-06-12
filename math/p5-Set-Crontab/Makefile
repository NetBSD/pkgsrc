# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:36 joerg Exp $

DISTNAME=	Set-Crontab-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Crontab/
COMMENT=	Perl module to parse crontab(5)-like lists of integers

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Set/Crontab/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
