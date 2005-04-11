# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:35 tv Exp $

DISTNAME=	String-Format-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	epg@NetBSD.org
COMMENT=	Perl module for sprintf-like string formatting capabilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/String/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
