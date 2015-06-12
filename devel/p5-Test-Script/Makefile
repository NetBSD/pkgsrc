# $NetBSD: Makefile,v 1.15 2015/06/12 10:49:52 wiz Exp $
#

DISTNAME=	Test-Script-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AD/ADAMK/
COMMENT=	Test::Script - Cross-platform basic tests for scripts
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IPC-Run3>=0.039:../../devel/p5-IPC-Run3
DEPENDS+=	p5-Probe-Perl>=0.01:../../devel/p5-Probe-Perl

PERL5_PACKLIST=		auto/Test/Script/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
