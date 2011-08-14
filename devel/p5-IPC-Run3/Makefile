# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:12 obache Exp $
#

DISTNAME=	IPC-Run3-0.044
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/
COMMENT=	IPC::Run3 - run a subprocess in batch mode
LICENSE=	original-bsd OR artistic OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/IPC/Run3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
