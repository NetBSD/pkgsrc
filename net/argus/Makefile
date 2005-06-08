# $NetBSD: Makefile,v 1.5 2005/06/08 14:48:13 wiz Exp $
#

DISTNAME=	argus-3.3
PKGREVISION= 	2
CATEGORIES= 	net
MASTER_SITES=	http://www.tcp4me.com/code/argus-archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	argus@tcp4me.com
HOMEPAGE=	http://argus.tcp4me.com/
COMMENT=	System and Network Monitoring Application

BUILD_DEPENDS+=	fping>=2.4b2:../../net/fping
BUILD_DEPENDS+=	p5-GD>=2.11:../../graphics/p5-GD
BUILD_DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
BUILD_DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
BUILD_DEPENDS+=	p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
BUILD_DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI

USE_TOOLS+=		perl
USE_PKGINSTALL=		yes
HAS_CONFIGURE= 		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure

CONFIGURE_ARGS+=	--bin_dir  ${PREFIX}/bin
CONFIGURE_ARGS+=	--sbin_dir ${PREFIX}/sbin
CONFIGURE_ARGS+=	--lib_dir  ${PREFIX}/lib/argus
CONFIGURE_ARGS+=	--data_dir ${VARBASE}/argus

RCD_SCRIPTS=		argusd

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
