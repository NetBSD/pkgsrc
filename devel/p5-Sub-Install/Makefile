# $NetBSD: Makefile,v 1.4 2009/01/21 00:11:00 he Exp $

DISTNAME=	Sub-Install-0.925
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Install/
COMMENT=	Install subroutines into packages easily

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Sub/Install/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
