# $NetBSD: Makefile,v 1.59 2023/06/06 12:40:18 riastradh Exp $
#
DISTNAME=	dinotrace-9.4f
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=veripool/}
GITHUB_TAG=	v9.4f

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.veripool.org/dinotrace/
COMMENT=	Tool for viewing the output of digital simulators
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	gtexinfo-[0-9]*:../../devel/gtexinfo
TOOL_DEPENDS+=	web2c>=2020:../../print/web2c
TOOL_DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo

GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_TOOLS+=		aclocal autoconf automake gmake perl makeinfo

pre-configure:
	cd ${WRKSRC}; aclocal
	cd ${WRKSRC}; autoconf

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
