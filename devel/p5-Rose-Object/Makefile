# $NetBSD: Makefile,v 1.9 2010/02/02 18:19:00 sno Exp $

DISTNAME=	Rose-Object-0.856
PKGNAME=	p5-${DISTNAME:S/854/85.4/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-Object/
COMMENT=	Very simple class base class used by Rose objects
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Rose/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
