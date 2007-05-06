# $NetBSD: Makefile,v 1.1.1.1 2007/05/06 14:00:56 heinz Exp $
#

DISTNAME=	Net-OpenID-Consumer-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-OpenID-Consumer/
COMMENT=	Perl library for consumers of OpenID identities

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Crypt-DH>=0.05:../../security/p5-Crypt-DH
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Time-Local-[0-9]*:../../time/p5-Time-Local
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-URI-Fetch>=0.02:../../www/p5-URI-Fetch

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/OpenID/Consumer/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
