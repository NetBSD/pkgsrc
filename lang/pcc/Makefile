# $NetBSD: Makefile,v 1.2 2007/09/15 10:12:31 agc Exp $

DISTNAME=	pcc-current
PKGNAME=	pcc-0.9.8
CATEGORIES=	lang
MASTER_SITES=	ftp://226.net120.skekraft.net/pcc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ludd.ltu.se/~ragge/pcc/
COMMENT=	Portable C compiler

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin libexec

.include "../../mk/bsd.pkg.mk"
