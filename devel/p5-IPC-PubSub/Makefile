# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:12 obache Exp $
#

DISTNAME=	IPC-PubSub-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IPC-PubSub/
COMMENT=	Perl 5 module providing interprocess publish/subscribe channels

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IPC/PubSub/.packlist

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DBM-Deep>=1.00:../../databases/p5-DBM-Deep
DEPENDS+=	p5-Data-UUID-[0-9]*:../../devel/p5-Data-UUID

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
