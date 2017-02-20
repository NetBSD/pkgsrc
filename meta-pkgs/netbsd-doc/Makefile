# $NetBSD: Makefile,v 1.21 2017/02/20 09:35:17 wiz Exp $
#

DISTNAME=	netbsd-doc-1.3
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package including all packages to convert SGML->HTML

DEPENDS+=	opensp>=1.4:../../textproc/opensp
DEPENDS+=	openjade-[0-9]*:../../textproc/openjade
DEPENDS+=	docbook>=4.0:../../textproc/docbook
DEPENDS+=	iso8879>=1986:../../textproc/iso8879
DEPENDS+=	iso12083>=1993:../../textproc/iso12083
DEPENDS+=	dsssl-docbook-modular>=1.54:../../textproc/dsssl-docbook-modular
DEPENDS+=	html>=4.0:../../textproc/html
DEPENDS+=	tidy-[0-9]*:../../www/tidy

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
