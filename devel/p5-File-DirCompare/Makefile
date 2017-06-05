# $NetBSD: Makefile,v 1.11 2017/06/05 14:22:58 ryoon Exp $

DISTNAME=	File-DirCompare-0.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-DirCompare/
COMMENT=	Perl module to compare two directories using callbacks
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/DirCompare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
