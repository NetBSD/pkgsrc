# $NetBSD: Makefile,v 1.11 2014/10/09 14:07:03 wiz Exp $

DISTNAME=	Pod-Parser-1.62
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Parser/
COMMENT=	POD filters and translators

PERL5_PACKLIST=		auto/Pod/Parser/.packlist

pre-configure:
	@${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
