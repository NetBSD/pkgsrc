# $NetBSD: Makefile,v 1.8 2017/06/05 14:24:51 ryoon Exp $

DISTNAME=	Text-Patch-1.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module patches text with given patch
HOMEPAGE=	http://search.cpan.org/dist/Text-Patch/
LICENSE=	gnu-gpl-v2

DEPENDS+=		p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Text/Patch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
