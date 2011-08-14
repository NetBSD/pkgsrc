# $NetBSD: Makefile,v 1.17 2011/08/14 12:26:48 obache Exp $

DISTNAME=	Want-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/ROBIN/} # this is a hack

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Want/
COMMENT=	Perl module providing a generalisation of wantarray

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Want/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
