# $NetBSD: Makefile,v 1.23 2018/08/22 09:45:45 wiz Exp $

DISTNAME=	File-Tail-1.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Tail/
COMMENT=	Perl5 module for reading from continuously updated files

#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>1.12}:../../time/p5-Time-HiRes

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Tail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
