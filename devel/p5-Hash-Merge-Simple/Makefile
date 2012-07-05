# $NetBSD: Makefile,v 1.1 2012/07/05 13:08:15 sno Exp $

DISTNAME=	Hash-Merge-Simple-0.051
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hash-Merge-Simple/
COMMENT=	Perl 5 module to simply merge two or more hashes recursively
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Hash/Merge/Simple/.packlist

DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone

BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
