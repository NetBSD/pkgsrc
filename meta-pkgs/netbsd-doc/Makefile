# $NetBSD: Makefile,v 1.12 2005/02/21 20:26:12 hubertf Exp $
#

DISTNAME=	netbsd-doc-1.2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Meta-package including all packages to convert SGML->HTML

DEPENDS+=	opensp>=1.4:../../textproc/opensp
DEPENDS+=	jade>=1.2.1nb3:../../textproc/jade
DEPENDS+=	docbook>=4.0:../../textproc/docbook
DEPENDS+=	iso8879>=1986:../../textproc/iso8879
DEPENDS+=	iso12083>=1993:../../textproc/iso12083
DEPENDS+=	dsssl-docbook-modular>=1.54:../../textproc/dsssl-docbook-modular
DEPENDS+=	html>=4.0:../../textproc/html
DEPENDS+=	tidy>=20031002:../../www/tidy

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
