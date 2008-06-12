# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:35 joerg Exp $
#

DISTNAME=	Net-LMTP-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~lhoward/${DISTNAME}/
COMMENT=	Local Mail Transfer Protocol Client

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/LMTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
