# $NetBSD: Makefile,v 1.6 2013/11/05 02:47:59 wen Exp $

DISTNAME=	File-Path-Tiny-0.7
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Path-Tiny/
COMMENT=	Perl 5 module providing recursive mkdir and rmdir
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Path/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
