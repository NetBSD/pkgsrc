# $NetBSD: Makefile,v 1.4 2012/09/03 11:16:26 sno Exp $

DISTNAME=	DBIx-Class-Cursor-Cached-1.0.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Cursor-Cached/
COMMENT=	Cursor class with built-in caching support
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class>=0.08004:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

BUILD_DEPENDS+=	p5-Cache-Cache-[0-9]*:../../devel/p5-Cache-Cache

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Class/Cursor/Cached/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
