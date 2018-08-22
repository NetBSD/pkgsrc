# $NetBSD: Makefile,v 1.16 2018/08/22 09:44:01 wiz Exp $

DISTNAME=	File-Next-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Next/
COMMENT=	Perl 5 module providing a file-finding iterator
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Next/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
