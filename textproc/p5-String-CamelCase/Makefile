# $NetBSD: Makefile,v 1.10 2018/03/25 15:56:43 wiz Exp $

DISTNAME=		String-CamelCase-0.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/String-CamelCase/
COMMENT=		Convert string to camelcase and vice versa
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/String/CamelCase/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
