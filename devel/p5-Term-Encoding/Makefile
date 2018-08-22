# $NetBSD: Makefile,v 1.8 2018/08/22 09:44:42 wiz Exp $

DISTNAME=		Term-Encoding-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Term-Encoding/
COMMENT=		Detect encoding of the current terminal
LICENSE=		${PERL5_LICENSE}

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Term/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
