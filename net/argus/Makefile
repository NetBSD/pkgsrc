# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:22 joerg Exp $
#

DISTNAME=	argus-3.3
PKGREVISION= 	3
CATEGORIES= 	net
MASTER_SITES=	http://www.tcp4me.com/code/argus-archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	argus@tcp4me.com
HOMEPAGE=	http://argus.tcp4me.com/
COMMENT=	System and Network Monitoring Application

DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	p5-GD>=2.11:../../graphics/p5-GD
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI

USE_TOOLS+=		perl:run
HAS_CONFIGURE= 		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure

CONFIGURE_ARGS+=	--bin_dir  ${PREFIX}/bin
CONFIGURE_ARGS+=	--sbin_dir ${PREFIX}/sbin
CONFIGURE_ARGS+=	--lib_dir  ${PREFIX}/lib/argus
CONFIGURE_ARGS+=	--data_dir ${VARBASE}/argus
CONFIGURE_ENV+=		PERL=${TOOLS_PERL5:Q}

RCD_SCRIPTS=		argusd

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
