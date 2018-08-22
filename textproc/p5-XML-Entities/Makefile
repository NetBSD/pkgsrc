# $NetBSD: Makefile,v 1.15 2018/08/22 09:47:06 wiz Exp $

DISTNAME=	XML-Entities-1.0002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sixtease/XML-Entities/
COMMENT=	Decode strings with XML entities
LICENSE=	${PERL5_LICENSE}

WRKSRC=		${WRKDIR}/XML-Entities

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/XML/Entities/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
