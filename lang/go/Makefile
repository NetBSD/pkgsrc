# $NetBSD: Makefile,v 1.69 2018/11/21 11:25:00 jperkin Exp $

DISTNAME=	# empty
PKGNAME=	go-${GO${GOVERSSUFFIX}_VERSION}
CATEGORIES=	lang
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://golang.org/
COMMENT=	Meta package providing the current release of the Go language
LICENSE=	modified-bsd

META_PACKAGE=	yes

DEPENDS+=	${GO_PACKAGE_DEP}

.include "../../lang/go/version.mk"
.include "../../mk/bsd.pkg.mk"
