# $NetBSD: Makefile,v 1.3 2012/09/11 19:47:00 asau Exp $
#

DISTNAME=	bz2-0.2.2
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://rubyforge.org/frs/download.php/56889/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/bz2/
COMMENT=	Ruby interface to the library libbzip2
LICENSE=	ruby-license

USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS+=	--with-bz2-dir=${BUILDLINK_PREFIX.bzip2}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
