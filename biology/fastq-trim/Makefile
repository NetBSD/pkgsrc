# $NetBSD: Makefile,v 1.5 2023/12/24 10:18:27 nros Exp $

DISTNAME=	fastq-trim-0.1.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}

OWNER=		bacon@NetBSD.org
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
