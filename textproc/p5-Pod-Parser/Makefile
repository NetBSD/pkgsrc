# $NetBSD: Makefile,v 1.21 2022/06/28 11:36:22 wiz Exp $

DISTNAME=	Pod-Parser-1.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Parser
COMMENT=	POD filters and translators
LICENSE=	artistic

CONFLICTS=	mrtg-[0-9]*

PERL5_PACKLIST=		auto/Pod/Parser/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
