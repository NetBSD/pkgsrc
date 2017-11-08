# $NetBSD: Makefile,v 1.14 2017/11/08 16:35:55 wiz Exp $

DISTNAME=	File-Save-Home-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Save-Home/
COMMENT=	Place file safely under user home directory
LICENSE=	${PERL5_LICENSE}

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-String-Random-[0-9]*:../../security/p5-String-Random

PERL5_PACKLIST=		auto/File/Save/Home/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
