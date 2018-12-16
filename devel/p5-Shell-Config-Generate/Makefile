# $NetBSD: Makefile,v 1.4 2018/12/16 06:53:27 wen Exp $

DISTNAME=	Shell-Config-Generate-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Shell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Shell-Config-Generate/
COMMENT=	Portably generate config for any shell
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Shell-Guess-[0-9]*:../../devel/p5-Shell-Guess
BUILD_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=	auto/Shell/Config/Generate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
