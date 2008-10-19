# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:53 he Exp $

DISTNAME=	ExtUtils-Install-1.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~autrijus/ExtUtils-Install/
COMMENT=	Install files from here to there

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/ExtUtils/Install/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
