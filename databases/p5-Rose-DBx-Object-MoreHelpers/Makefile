# $NetBSD: Makefile,v 1.1.1.1 2008/09/11 11:53:31 he Exp $

DISTNAME=	Rose-DBx-Object-MoreHelpers-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-DBx-Object-MoreHelpers/
COMMENT=	More mixin helpers for RDBO

DEPENDS+=	p5-Rose-DB-Object>=0.770:../../databases/p5-Rose-DB-Object
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Rose/DBx/Object/MoreHelpers/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
