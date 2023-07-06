# $NetBSD: Makefile,v 1.24 2023/07/06 09:41:44 wiz Exp $

DISTNAME=	Pod-Parser-1.66
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Parser
COMMENT=	POD filters and translators
LICENSE=	artistic

PERL5_PACKLIST=		auto/Pod/Parser/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
