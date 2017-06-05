# $NetBSD: Makefile,v 1.11 2017/06/05 14:23:00 ryoon Exp $

DISTNAME=	File-Path-Expand-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Path-Expand/
COMMENT=	Perl 5 module to expand filenames
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Path/Expand/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
