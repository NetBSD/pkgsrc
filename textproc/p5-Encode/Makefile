# $NetBSD: Makefile,v 1.2 2006/10/24 14:09:43 obache Exp $

DISTNAME=	Encode-2.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/~dankogai/Encode/
COMMENT=	Provides interfaces between strings and the rest of the system

PERL5_REQD+=	5.7.3

PERL5_PACKLIST=	auto/Encode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
