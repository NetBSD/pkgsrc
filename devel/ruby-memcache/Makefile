# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:28:10 jlam Exp $

DISTNAME=	ruby-memcache-0.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	devel
MASTER_SITES=	http://rubyforge.org/frs/download.php/2484/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Ruby wrapper for memcache

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_EXTCONF=	yes

.include "../../lang/ruby/modules.mk"

.include "../../devel/libmemcache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
