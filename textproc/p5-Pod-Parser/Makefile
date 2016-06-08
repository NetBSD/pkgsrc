# $NetBSD: Makefile,v 1.14 2016/06/08 19:24:32 wiz Exp $

DISTNAME=	Pod-Parser-1.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Parser/
COMMENT=	POD filters and translators
LICENSE=	artistic

CONFLICTS=	mrtg-[0-9]*

PERL5_PACKLIST=		auto/Pod/Parser/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
