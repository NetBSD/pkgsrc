# $NetBSD: Makefile,v 1.4 2010/08/21 16:35:37 seb Exp $
#

DISTNAME=	Authen-TacacsPlus-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mikem/Authen-TacacsPlus/TacacsPlus.pm
COMMENT=	Perl extension for authentication using tacacs+ server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Authen/TacacsPlus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
