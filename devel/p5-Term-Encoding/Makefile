# $NetBSD: Makefile,v 1.1 2014/02/10 13:33:17 wen Exp $

DISTNAME=		Term-Encoding-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Term-Encoding/
COMMENT=		Detect encoding of the current terminal
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Term/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
