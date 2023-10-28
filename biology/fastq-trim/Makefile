# $NetBSD: Makefile,v 1.4 2023/10/28 20:35:44 bacon Exp $

DISTNAME=	fastq-trim-0.1.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/Fastq-trim
COMMENT=	Lightening fast sequence read trimmer
LICENSE=	2-clause-bsd

MAKE_ENV=	VERSION=${PKGVERSION}

LDFLAGS.SunOS=	-lresolv

pre-build:
	(cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend)

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
