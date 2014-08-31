# $NetBSD: Makefile,v 1.20 2014/08/31 06:49:41 wen Exp $

DISTNAME=	PathTools-3.47
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PathTools/
COMMENT=	Perl module for portably manipulating file specifications
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-File-Spec-[0-9]*

CFLAGS+=	-DHAS_GETCWD

PERL5_PACKLIST=	auto/Cwd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
