# $NetBSD: Makefile,v 1.5 2016/06/08 19:23:33 wiz Exp $

DISTNAME=		Term-Encoding-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Term-Encoding/
COMMENT=		Detect encoding of the current terminal
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Term/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
