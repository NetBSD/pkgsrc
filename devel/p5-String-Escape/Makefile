# $NetBSD: Makefile,v 1.17 2021/05/24 19:51:33 wiz Exp $

DISTNAME=	String-Escape-2010.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

HOMEPAGE=	https://metacpan.org/release/String-Escape
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Registry of string functions, including backslash escapes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/String/Escape/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
