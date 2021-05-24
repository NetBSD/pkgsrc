# $NetBSD: Makefile,v 1.21 2021/05/24 19:50:42 wiz Exp $

DISTNAME=	File-Next-1.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Next
COMMENT=	Perl 5 module providing a file-finding iterator
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Next/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
