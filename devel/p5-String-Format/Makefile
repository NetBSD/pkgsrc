# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:26 joerg Exp $

DISTNAME=	String-Format-1.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	epg@NetBSD.org
COMMENT=	Perl module for sprintf-like string formatting capabilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/String/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
