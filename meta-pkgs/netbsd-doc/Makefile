# $NetBSD: Makefile,v 1.1.1.1 2000/07/09 19:25:28 hubertf Exp $
#

DISTNAME=	netbsd-doc-1.0
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	opensp>=1.4:../../textproc/opensp
DEPENDS+=	jade>=1.2.1:../../textproc/jade
DEPENDS+=	docbook>=3.0:../../textproc/docbook
DEPENDS+=	iso8879-1986:../../textproc/iso8879
DEPENDS+=	iso12083-1993:../../textproc/iso12083
DEPENDS+=	dsssl-docbook-modular>=1.41:../../textproc/dsssl-docbook-modular
DEPENDS+=	html>=4.0:../../textproc/html

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
