# $NetBSD: Makefile,v 1.12 2015/02/22 14:26:47 wiedi Exp $

DISTNAME=	spiped-1.5.0
CATEGORIES=	net security
MASTER_SITES=	http://www.tarsnap.com/spiped/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tarsnap.com/spiped/
COMMENT=	Tool for creating symmetrically encrypted and authenticated pipes
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin
MAKE_FLAGS+=	MAN1DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

LDADD_EXTRA=	${COMPILER_RPATH_FLAG:Q}${BUILDLINK_PREFIX.openssl}/lib

CFLAGS.SunOS+=	-D__EXTENSIONS__

SMF_METHODS=	spiped

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
LDADD_EXTRA+=	-lsocket -lnsl
.endif

MAKE_ENV+=	LDADD_EXTRA="${LDADD_EXTRA}"

INSTALLATION_DIRS+=	share/doc/spiped ${PKGMANDIR}/man1

.if ${INIT_SYSTEM} == "smf"
MESSAGE_SRC+=	MESSAGE.smf
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/spiped

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
