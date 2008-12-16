# $NetBSD: Makefile,v 1.6 2008/12/16 21:05:35 he Exp $

DISTNAME=	Rose-Object-0.854
PKGNAME=	p5-${DISTNAME:S/853/85.3/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-Object/
COMMENT=	Very simple class base class used by Rose objects

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Rose/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
