# $NetBSD: Makefile,v 1.72 2020/03/11 19:20:36 nia Exp $

DISTNAME=	cue-snap-20180813
PKGNAME=	${DISTNAME:S/snap-//}
CATEGORIES=	mail
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/cue/snap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Mh-e like mail user agent
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-openssl # XXX broken with OpenSSL 1.1
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
INSTALLATION_DIRS+=	bin share/doc/cue share/examples/cue

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cue ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sample.cuerc \
		${DESTDIR}${PREFIX}/share/examples/cue
	${INSTALL_DATA} ${WRKSRC}/cue.hlp ${DESTDIR}${PREFIX}/share/doc/cue

.include "options.mk"
#.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
