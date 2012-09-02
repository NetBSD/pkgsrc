# $NetBSD: Makefile,v 1.7 2012/09/02 04:42:54 wen Exp $

DISTNAME=	Statistics-Descriptive-3.0604
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Statistics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Statistics-Descriptive/
COMMENT=	Perl module of basic descriptive statistical functions
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Statistics/Descriptive/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
