# $NetBSD: Makefile,v 1.7 2012/07/06 11:32:01 sno Exp $

DISTNAME=	Sub-Install-0.926
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Install/
COMMENT=	Install subroutines into packages easily
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Sub/Install/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
