# $NetBSD: Makefile,v 1.7 2009/01/02 22:18:37 he Exp $

DISTNAME=	Rose-Object-0.854
PKGNAME=	p5-${DISTNAME:S/854/85.4/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-Object/
COMMENT=	Very simple class base class used by Rose objects

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Rose/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
