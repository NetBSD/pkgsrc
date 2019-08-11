# $NetBSD: Makefile,v 1.24 2019/08/11 13:20:16 wiz Exp $

DISTNAME=	Rose-Object-0.860
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Rose-Object
COMMENT=	Very simple class base class used by Rose objects
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Rose/Object/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
