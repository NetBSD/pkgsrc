# $NetBSD: Makefile,v 1.2 2008/02/06 15:25:28 rhaen Exp $
#

DISTNAME=	IPC-Run3-0.040
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RJ/RJBS/
COMMENT=	IPC::Run3 - run a subprocess in batch mode

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/IPC/Run3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
