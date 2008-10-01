# $NetBSD: Makefile,v 1.5 2008/10/01 08:43:09 apb Exp $

.include "../../security/dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
PKGREVISION=	2
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

post-configure:
	( cd ${WRKSRC} \
	  && grep '#define.*HAVE_SYS_QUEUE_H' config.h >/dev/null \
	  && mv missing/sys/queue.h missing/sys/queue.h.fake )

post-install:
	${RM} ${PREFIX}/${PKGMANDIR}/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
