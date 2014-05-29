# $NetBSD: Makefile,v 1.15 2014/05/29 23:36:17 wiz Exp $

DISTNAME=	String-Format-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

HOMEPAGE=	http://search.cpan.org/dist/String-Format/
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for sprintf-like string formatting capabilities
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/String/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
