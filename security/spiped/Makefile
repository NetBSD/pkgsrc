# $NetBSD: Makefile,v 1.4 2014/05/14 13:53:53 wiedi Exp $

DISTNAME=	spiped-1.3.1
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	http://www.tarsnap.com/spiped/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tarsnap.com/spiped/
COMMENT=	Tool for creating symmetrically encrypted and authenticated pipes
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin
MAKE_FLAGS+=	MAN1DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

CFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LDADD_EXTRA="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	share/doc/spiped ${PKGMANDIR}/man1

SMF_METHODS=	spiped
.if ${INIT_SYSTEM} == "smf"
MESSAGE_SRC+=	MESSAGE.smf
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/spiped

.include "../../mk/bsd.pkg.mk"
