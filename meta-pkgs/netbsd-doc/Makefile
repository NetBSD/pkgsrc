# $NetBSD: Makefile,v 1.3 2001/02/17 17:59:18 wiz Exp $
#

DISTNAME=	netbsd-doc-1.1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Meta-pkg including all pkgs to convert SGML->HTML

DEPENDS+=	opensp>=1.4:../../textproc/opensp
DEPENDS+=	jade>=1.2.1:../../textproc/jade
DEPENDS+=	docbook>=4.0:../../textproc/docbook
DEPENDS+=	iso8879-1986:../../textproc/iso8879
DEPENDS+=	iso12083-1993:../../textproc/iso12083
DEPENDS+=	dsssl-docbook-modular>=1.54:../../textproc/dsssl-docbook-modular
DEPENDS+=	html>=4.0:../../textproc/html

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
