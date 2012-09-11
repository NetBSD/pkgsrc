# $NetBSD: Makefile,v 1.5 2012/09/11 08:35:40 sno Exp $

DISTNAME=	File-Next-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Next/
COMMENT=	Perl 5 module providing a file-finding iterator
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Next/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
