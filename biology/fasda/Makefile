# $NetBSD: Makefile,v 1.7 2024/11/29 13:14:13 bacon Exp $

DISTNAME=	fasda-0.1.5.8
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	4ae61db81be44016c34e7ce127f1c63dcbe52a4a

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda
COMMENT=	Fast and simple differential analysis
LICENSE=	2-clause-bsd

DEPENDS=	stringtie>0:../../biology/stringtie

LDFLAGS.SunOS+=	-lresolv
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
