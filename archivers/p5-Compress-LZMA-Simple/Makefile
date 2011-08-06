# $NetBSD: Makefile,v 1.6 2011/08/06 12:30:17 adam Exp $

DISTNAME=	Compress-LZMA-Simple-0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Compress-LZMA-Simple/
COMMENT=	Perl interface of lzmalib
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Compress/LZMA/Simple/.packlist

.include "../../archivers/lzmalib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
