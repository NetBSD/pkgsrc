# $NetBSD: Makefile,v 1.1.1.1 2004/11/06 21:49:35 epg Exp $

DISTNAME=	PerlIO-eol-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for normalizing line endings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PerlIO/eol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
