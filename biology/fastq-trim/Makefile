# $NetBSD: Makefile,v 1.1 2022/11/06 22:49:37 bacon Exp $

DISTNAME=	fastq-trim-0.1.1.16
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	58a016f250a9b785bfed574ce471ec7e23cdaa4a

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/Fastq-trim
COMMENT=	Lightening fast sequence read trimmer
LICENSE=	2-clause-bsd

MAKE_ENV=	VERSION=${PKGVERSION}

LDFLAGS.SunOS=	-lresolv

pre-build:
	(cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend)

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
