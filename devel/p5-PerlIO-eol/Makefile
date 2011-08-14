# $NetBSD: Makefile,v 1.11 2011/08/14 12:26:31 obache Exp $

DISTNAME=	PerlIO-eol-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PerlIO-eol/
COMMENT=	Perl module for normalizing line endings

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PerlIO/eol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
