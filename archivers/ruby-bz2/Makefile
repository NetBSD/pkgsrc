# $NetBSD: Makefile,v 1.2 2011/02/21 16:01:10 taca Exp $
#

DISTNAME=	bz2-0.2.2
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://rubyforge.org/frs/download.php/56889/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/bz2/
COMMENT=	Ruby interface to the library libbzip2
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS+=	--with-bz2-dir=${BUILDLINK_PREFIX.bzip2}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
