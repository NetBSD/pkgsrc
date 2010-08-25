# $NetBSD: Makefile,v 1.1.1.1 2010/08/25 22:35:38 seb Exp $
#

DISTNAME=	File-Path-Tiny-0.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Path-Tiny/
COMMENT=	Perl 5 module providing recursive mkdir and rmdir
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/Path/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
