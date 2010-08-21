# $NetBSD: Makefile,v 1.3 2010/08/21 16:35:09 seb Exp $
#

DISTNAME=	Net-validMX-2.2.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~kmcgrail/Net-validMX-2.2.0/
COMMENT=	Use DNS and/or regular expressions to verify a email address
LICENSE=	artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Net-DNS>=0.53:../../net/p5-Net-DNS

PERL5_PACKLIST=	auto/Net/validMX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
