# $NetBSD: Makefile,v 1.7 2019/06/30 20:16:57 nia Exp $
#

DISTNAME=	String-Similarity-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/String-Similarity
COMMENT=	Calculate the similarity of two strings
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/String/Similarity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
