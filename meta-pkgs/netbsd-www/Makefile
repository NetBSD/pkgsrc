# $NetBSD: Makefile,v 1.9 2004/10/12 13:48:29 tv Exp $
#

DISTNAME=	netbsd-www-1.1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	grant@NetBSD.org
COMMENT=	Packages required to build the NetBSD.org web site

DEPENDS+=	docbook-website>=2.3nb3:../../textproc/docbook-website
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt
DEPENDS+=	ImageMagick>=5.5.7.11nb1:../../graphics/ImageMagick
DEPENDS+=	xearth>=1.1:../../x11/xearth
DEPENDS+=	opensp>=1.1:../../textproc/opensp
DEPENDS+=	w3m>=0.5.1:../../www/w3m

USE_PERL5=	run
EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
NO_MTREE=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
