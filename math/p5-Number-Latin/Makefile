# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:36 joerg Exp $

DISTNAME=		Number-Latin-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		Perl module for "lower/upper-latin" numbering system

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Number/Latin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
