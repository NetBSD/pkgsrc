# $NetBSD: Makefile,v 1.33 2019/08/11 13:20:28 wiz Exp $

DISTNAME=	Test-Cmd-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.baldmt.com/Test-Cmd/
COMMENT=	Perl5 module for testing of external commands and scripts
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
