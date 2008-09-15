# $NetBSD: Makefile,v 1.1.1.1 2008/09/15 17:53:41 rhaen Exp $
#

DISTNAME=	Net-Jifty-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Jifty/
COMMENT=	Interface to online Jifty applications

DEPENDS+=	p5-Email-Address-[0-9]*:../../mail/p5-Email-Address
DEPENDS+=	p5-Encode-[0-9]*:../../textproc/p5-Encode
DEPENDS+=	p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/Net/Jifty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
