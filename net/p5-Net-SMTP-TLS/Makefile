# $NetBSD: Makefile,v 1.1.1.1 2010/08/04 15:17:50 sno Exp $
#

DISTNAME=	Net-SMTP-TLS-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-SMTP-TLS/
COMMENT=	Perl5 SMTP client module supporting TLS and AUTH
LICENSE=	${PERL5_LICENSE} # see README

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

USE_LANGUAGES=		# none

PERL5_PACKLIST=		auto/Net/SMTP/TLS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
