# $NetBSD: Makefile,v 1.24 2020/04/12 11:01:34 bsiegert Exp $

DISTNAME=	cobra-0.0.3
PKGNAME=	go-${DISTNAME}
PKGREVISION=	16
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/cobra
COMMENT=	Commander for modern Go CLI interactions
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/spf13/cobra

.include "../../devel/go-pflag/buildlink3.mk"
.include "../../devel/go-viper/buildlink3.mk"
.include "../../textproc/go-md2man/buildlink3.mk"
.include "../../devel/go-homedir/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
