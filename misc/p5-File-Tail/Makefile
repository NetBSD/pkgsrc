# $NetBSD: Makefile,v 1.30 2024/11/16 12:06:05 wiz Exp $

DISTNAME=	File-Tail-1.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Tail
COMMENT=	Perl5 module for reading from continuously updated files

#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>1.12}:../../time/p5-Time-HiRes

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Tail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
