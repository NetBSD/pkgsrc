# $NetBSD: Makefile,v 1.6 2025/03/06 01:19:03 bacon Exp $

DISTNAME=	fastq-trim-0.1.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/Fastq-trim
COMMENT=	Lightening fast sequence read trimmer
LICENSE=	2-clause-bsd

MAKE_ENV=	VERSION=${PKGVERSION}
INSTALL_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

LDFLAGS.SunOS=	-lresolv

pre-build:
	(cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend)

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
