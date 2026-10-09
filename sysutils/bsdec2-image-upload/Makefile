# $NetBSD: Makefile,v 1.8 2026/10/09 07:58:02 drixter Exp $

DISTNAME=	bsdec2-image-upload-1.5.0
DISTFILES=	${DISTNAME}.tar.gz
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cperciva/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/cperciva/bsdec2-image-upload/
COMMENT=	Tool for creating Amazon EC2 AMIs
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/bsdec2-image-upload-${PKGVERSION_NOREV}

MAKE_ENV+=	NOMAN=1
CFLAGS+=	-DCERTFILE=\"${PREFIX}/share/mozilla-rootcerts/cacert.pem\"

LDFLAGS.SunOS+=	-lsocket

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
CFLAGS+=	-Wno-error=pointer-sign \
		-Wno-error=maybe-uninitialized \
		-Wno-error=discarded-qualifiers
.elif !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-unknown-warning-option -Wno-pointer-sign \
		-Wno-incompatible-pointer-types-discards-qualifiers
.endif

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdec2-image-upload/bsdec2-image-upload ${DESTDIR}${PREFIX}/bin

DEPENDS+=	mozilla-rootcerts>=1.0:../../security/mozilla-rootcerts
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
