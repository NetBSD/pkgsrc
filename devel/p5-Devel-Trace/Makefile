# $NetBSD: Makefile,v 1.19 2024/11/16 12:04:08 wiz Exp $

DISTNAME=	Devel-Trace-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Trace
COMMENT=	Print out each line before it is executed (like sh -x)
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Trace/.packlist

pre-install:
	${FIND} ${WRKSRC} -name demo.pl | ${XARGS} ${CHMOD} -x

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
