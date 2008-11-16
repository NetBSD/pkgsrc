# $NetBSD: Makefile,v 1.6 2008/11/16 23:53:04 he Exp $
#

DISTNAME=	Hook-LexWrap-0.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hlw
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hook/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hook-LexWrap/
COMMENT=	Perl5 module providing lexically scoped subroutine wrappers

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Hook/LexWrap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
