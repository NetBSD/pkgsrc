# $NetBSD: Makefile,v 1.12 2005/02/19 00:45:58 wiz Exp $
#

DISTNAME=	netbsd-www-1.2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	grant@NetBSD.org
COMMENT=	Packages required to build the NetBSD.org web site

# we add an explicit dependency on docbook-xsl here since earlier versions
# generated slightly different html code, leading to a large number of
# unneccessary 'regen' commits
DEPENDS+=	docbook-xsl>=1.67.0:../../textproc/docbook-xsl
DEPENDS+=	docbook-website>=2.3nb3:../../textproc/docbook-website
DEPENDS+=	libxslt>=1.0.20:../../textproc/libxslt
DEPENDS+=	ImageMagick>=5.5.7.11nb1:../../graphics/ImageMagick
DEPENDS+=	xearth>=1.1:../../x11/xearth
DEPENDS+=	opensp>=1.1:../../textproc/opensp
DEPENDS+=	w3m>=0.4:../../www/w3m

USE_PERL5=	run
EXTRACT_ONLY=	# defined
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
NO_MTREE=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
