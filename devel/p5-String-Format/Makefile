# $NetBSD: Makefile,v 1.1.1.1 2005/04/03 01:03:39 epg Exp $

DISTNAME=	String-Format-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	epg@NetBSD.org
COMMENT=	Perl module for sprintf-like string formatting capabilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/String/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
