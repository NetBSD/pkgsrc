# $NetBSD: Makefile,v 1.12 2013/10/06 08:28:37 obache Exp $

.include "../../security/dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
PKGREVISION=	7
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

INSTALLATION_DIRS+=	${PKGMANDIR}/man8
INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

post-configure:
	( cd ${WRKSRC} \
	  && grep '#define.*HAVE_SYS_QUEUE_H' config.h >/dev/null \
	  && mv missing/sys/queue.h missing/sys/queue.h.fake )

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
