# $NetBSD: Makefile,v 1.27 2023/07/06 09:41:41 wiz Exp $

DISTNAME=		Net-Dict-2.22
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		net textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Net-Dict
COMMENT=		Client API for the DICT protocol defined in RFC2229
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Dict/.packlist

CONFLICTS=		dict-client-[0-9]*

DEPENDS+=		p5-AppConfig-Std-[0-9]*:../../devel/p5-AppConfig-Std
DEPENDS+=		p5-Tk-[0-9]*:../../x11/p5-Tk
# only for make test
DEPENDS+=		p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
# for make test
TOOL_DEPENDS+=		p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet
TOOL_DEPENDS+=		p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

REPLACE_PERL+=		dict
REPLACE_PERL+=		tkdict

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
