# $NetBSD: Makefile,v 1.60 2010/01/17 12:02:23 wiz Exp $

DISTNAME=	cue-snap-20090209
PKGNAME=	${DISTNAME:S/snap-//}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Mh-e like mail user agent
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
INSTALLATION_DIRS+=	bin share/doc/cue share/examples/cue

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cue ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sample.cuerc \
		${DESTDIR}${PREFIX}/share/examples/cue
	${INSTALL_DATA} ${WRKSRC}/cue.hlp ${DESTDIR}${PREFIX}/share/doc/cue

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
