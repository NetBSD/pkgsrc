# $NetBSD: Makefile,v 1.1 2021/08/31 15:55:16 bacon Exp $

DISTNAME=	biolibc-tools-0.1.0.36
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	0a781f7ec6566051382d7f4950fd673f73b7fb2f

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc-tools
COMMENT=	High-performance bioinformatics tools based on biolibc
LICENSE=	2-clause-bsd

BUILD_TARGET=	depend all
INSTALL_TARGET=	install-strip

.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../biology/biolibc/buildlink3.mk"
.include "../../devel/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
