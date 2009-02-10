# $NetBSD: Makefile,v 1.13 2009/02/10 17:47:59 joerg Exp $

DISTNAME=	argus-3.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tcp4me.com/code/argus-archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	argus@tcp4me.com
HOMEPAGE=	http://argus.tcp4me.com/
COMMENT=	System and Network Monitoring Application

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	fping>=2.4b2:../../net/fping
DEPENDS+=	p5-GD>=2.11:../../graphics/p5-GD
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI

USE_TOOLS+=		perl:run
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--bin_dir ${PREFIX}/bin
CONFIGURE_ARGS+=	--sbin_dir ${PREFIX}/sbin
CONFIGURE_ARGS+=	--lib_dir ${PREFIX}/lib/argus
CONFIGURE_ARGS+=	--data_dir ${PREFIX}/etc/argus
CONFIGURE_ENV+=		PERL=${TOOLS_PERL5:Q}

REPLACE_PERL+=		${WRKSRC}/built/argus-config

RCD_SCRIPTS=		argusd

INSTALL_MAKE_FLAGS+= 	INSTALL_BIN=${DESTDIR}${PREFIX}/bin \
			INSTALL_SBIN=${DESTDIR}${PREFIX}/sbin \
			INSTALL_LIB=${DESTDIR}${PREFIX}/lib/argus \
			INSTALL_DATA=${DESTDIR}${PREFIX}/etc/argus

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
