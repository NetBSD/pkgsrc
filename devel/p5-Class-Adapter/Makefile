# $NetBSD: Makefile,v 1.5 2008/10/30 21:35:34 he Exp $
#

DISTNAME=	Class-Adapter-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Adapter/
COMMENT=	Perl 5 module implementing the adapter design pattern

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/Class/Adapter/.packlist

post-extract:
	chmod -x ${WRKSRC}/lib/Class/*.pm ${WRKSRC}/lib/Class/Adapter/*.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
