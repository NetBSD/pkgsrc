# $NetBSD: Makefile,v 1.13 2019/08/11 13:23:38 wiz Exp $

DISTNAME=		String-CamelCase-0.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/String-CamelCase
COMMENT=		Convert string to camelcase and vice versa
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/String/CamelCase/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
