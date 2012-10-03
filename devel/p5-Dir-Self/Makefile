# $NetBSD: Makefile,v 1.4 2012/10/03 21:54:56 wiz Exp $

DISTNAME=	Dir-Self-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dir/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Dir-Self/
COMMENT=	Perl 5 __DIR__ constant for source file's directory
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Dir/Self/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
