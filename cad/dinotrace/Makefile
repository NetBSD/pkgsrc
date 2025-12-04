# $NetBSD: Makefile,v 1.62 2025/12/04 13:05:29 wiz Exp $

DISTNAME=	dinotrace-9.4f
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=veripool/}
GITHUB_TAG=	v9.4f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/veripool/dinotrace/blob/master/README.rst
COMMENT=	Tool for viewing the output of digital simulators
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	gtexinfo-[0-9]*:../../devel/gtexinfo
TOOL_DEPENDS+=	web2c>=2020:../../print/web2c
TOOL_DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
TOOL_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_TOOLS+=		aclocal autoconf automake gmake perl makeinfo

pre-configure:
	cd ${WRKSRC}; aclocal
	cd ${WRKSRC}; autoconf

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
