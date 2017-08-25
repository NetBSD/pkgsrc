# $NetBSD: Makefile,v 1.3 2017/08/25 17:03:26 jperkin Exp $

DISTNAME=	cobra-0.0.20170815
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	cb731b898346822cc0c225c28550a8a29d93c732
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/cobra
COMMENT=	Commander for modern Go CLI interactions
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/spf13/cobra

.include "../../devel/go-pflag/buildlink3.mk"
.include "../../devel/go-viper/buildlink3.mk"
.include "../../textproc/go-md2man/buildlink3.mk"
.include "../../devel/go-homedir/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
