# $NetBSD: Makefile,v 1.1.1.1 2004/09/26 04:41:00 epg Exp $

DISTNAME=	Pod-Escapes-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for decoding Pod E<...> sequences

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Pod/Escapes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
