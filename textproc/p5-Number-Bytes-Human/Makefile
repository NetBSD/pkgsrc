# $NetBSD: Makefile,v 1.2 2023/07/06 09:41:41 wiz Exp $

DISTNAME=	Number-Bytes-Human-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
# This expression is crazy but MASTER_SITE_PERL_CPAN has modules/by-module/
# baked into it, and the distfile is at
#   https://cpan.metacpan.org/authors/id/F/FE/FERREIRA/Number-Bytes-Human-0.11.tar.gz
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FE/FERREIRA/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Bytes::Human
COMMENT=	Convert byte count to human readable format
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Bytes/Human/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
