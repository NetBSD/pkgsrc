# $NetBSD: Makefile,v 1.11 2004/08/02 21:31:36 jlam Exp $

DISTNAME=		Archive-Tar-1.10
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tar
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module interface to manipulate tar files

DEPENDS+=		p5-IO-Zlib-[0-9]*:../../devel/p5-IO-Zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Tar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
