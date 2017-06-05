# $NetBSD: Makefile,v 1.12 2017/06/05 14:23:36 ryoon Exp $

DISTNAME=	String-Escape-2010.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

HOMEPAGE=	http://search.cpan.org/dist/String-Escape/
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Registry of string functions, including backslash escapes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/String/Escape/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
