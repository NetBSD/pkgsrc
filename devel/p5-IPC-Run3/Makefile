# $NetBSD: Makefile,v 1.14 2015/03/15 23:16:06 mef Exp $
#

DISTNAME=	IPC-Run3-0.048
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/
COMMENT=	IPC::Run3 - run a subprocess in batch mode
LICENSE=	original-bsd OR artistic OR gnu-gpl-v2

PERL5_PACKLIST=	auto/IPC/Run3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
