# $NetBSD: Makefile,v 1.27 2016/06/08 19:22:57 wiz Exp $

DISTNAME=	File-PathConvert-0.9
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/File-PathConvert/
COMMENT=	Convert paths and URLs from absolute to relative and vice versa
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/PathConvert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
