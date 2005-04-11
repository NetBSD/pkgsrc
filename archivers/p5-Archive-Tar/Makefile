# $NetBSD: Makefile,v 1.15 2005/04/11 21:44:49 tv Exp $

DISTNAME=		Archive-Tar-1.22
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tar
PKGREVISION=		1
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Archive-Tar/
COMMENT=		Perl5 module interface to manipulate tar files

DEPENDS+=		p5-IO-Zlib-[0-9]*:../../devel/p5-IO-Zlib
DEPENDS+=		p5-IO-String-[0-9]*:../../devel/p5-IO-String

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Tar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
