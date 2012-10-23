# $NetBSD: Makefile,v 1.12 2012/10/23 17:19:05 asau Exp $
#

DISTNAME=	rp-l2tp-0.3
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rp-l2tp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/rp-l2tp/
COMMENT=	User-space implementation of layer 2 tunnelling protocol

NOT_FOR_PLATFORM+=	Interix-*-* # no userland protocol stack support

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
USE_TOOLS+=		gmake

LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
LDFLAGS.NetBSD+=	-lutil

INSTALL_MAKE_FLAGS+=	RPM_INSTALL_ROOT=${DESTDIR:Q}

post-patch:
	for f in l2tp.conf.5 l2tpd.8; do				\
		${MV} ${WRKSRC}/man/$$f ${WRKSRC}/man/$$f.in &&		\
		${SED} -e 's|@SYSCONFDIR@|${PKG_SYSCONFDIR}|g'		\
			${WRKSRC}/man/$$f.in > ${WRKSRC}/man/$$f;	\
	done

.include "../../mk/bsd.pkg.mk"
