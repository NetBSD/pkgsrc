# $NetBSD: Makefile,v 1.3 2008/10/19 19:17:50 he Exp $
#

DISTNAME=	Config-Std-v0.0.4
PKGNAME=	p5-Config-Std-0.0.4
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Std/
COMMENT=	Perl 5 module providing a simple configuration-file system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Std-[0-9]*:../../devel/p5-Class-Std
DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/Std/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
