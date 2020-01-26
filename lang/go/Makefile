# $NetBSD: Makefile,v 1.70 2020/01/26 17:31:28 rillig Exp $

DISTNAME=	# empty
PKGNAME=	go-${GO${GOVERSSUFFIX}_VERSION}
CATEGORIES=	lang
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://golang.org/
COMMENT=	Meta package providing the current release of the Go language
LICENSE=	modified-bsd

META_PACKAGE=	yes

DEPENDS+=	${GO_PACKAGE_DEP}

.include "../../lang/go/version.mk"
.include "../../mk/bsd.pkg.mk"
