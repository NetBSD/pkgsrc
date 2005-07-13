# $NetBSD: Makefile,v 1.3 2005/07/13 18:01:29 jlam Exp $

DISTNAME=	String-Format-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	epg@NetBSD.org
COMMENT=	Perl module for sprintf-like string formatting capabilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/String/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
