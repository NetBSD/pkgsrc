# $NetBSD: Makefile,v 1.33 2002/05/04 05:59:04 taca Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		qpopper-${VERSION}
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/

PATCH_SITES=		http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=		qpopper4.0.4-ipv6-20020502.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://www.eudora.com/qpopper/
COMMENT=		Qualcomm's POP server for Eudora

USE_BUILDLINK_ONLY=	# defined

.include "Makefile.common"

PKG_USERS?=		${QPOPPER_USER}

pre-build:
	${SED} 's"/usr/local/lib"${LOCALBASE}/libexec"' \
		${WRKSRC}/man/popper.8 > ${WRKSRC}/man/popper.8.$$ && \
	${MV} -f ${WRKSRC}/man/popper.8.$$ ${WRKSRC}/man/popper.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/License.txt ${LOCALBASE}/share/doc/qpopper.License
	${INSTALL_DATA} ${WRKSRC}/samples/qpopper.config \
		 ${LOCALBASE}/share/examples

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
