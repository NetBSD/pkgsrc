# $NetBSD: Makefile,v 1.14 2013/12/09 14:17:49 obache Exp $

DISTNAME=	File-Tail-0.99.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
SVR4_PKGNAME=	p5fit
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Tail/
COMMENT=	Perl5 module for reading from continuously updated files

DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>1.12}:../../time/p5-Time-HiRes

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Tail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
