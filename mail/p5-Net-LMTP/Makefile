# $NetBSD: Makefile,v 1.8 2010/08/21 16:35:08 seb Exp $
#

DISTNAME=	Net-LMTP-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~lhoward/${DISTNAME}/
COMMENT=	Local Mail Transfer Protocol Client

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/LMTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
