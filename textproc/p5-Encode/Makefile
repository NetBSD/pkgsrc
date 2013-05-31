# $NetBSD: Makefile,v 1.22 2013/05/31 12:42:09 wiz Exp $

DISTNAME=	Encode-2.47
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dankogai/Encode/
COMMENT=	Provides interfaces between strings and the rest of the system
LICENSE=	${PERL5_LICENSE}

PERL5_REQD+=	5.7.3

PERL5_PACKLIST=	auto/Encode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
