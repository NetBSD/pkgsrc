# $NetBSD: Makefile,v 1.10 2009/04/12 00:42:50 sno Exp $

DISTNAME=	Encode-2.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dankogai/Encode/
COMMENT=	Provides interfaces between strings and the rest of the system

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_REQD+=	5.7.3

PERL5_PACKLIST=	auto/Encode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
