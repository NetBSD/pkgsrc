# $NetBSD: Makefile,v 1.21 2023/10/24 22:10:47 wiz Exp $

.include "../../security/dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
PKGREVISION=	14
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

INSTALLATION_DIRS+=	${PKGMANDIR}/man8
INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

CFLAGS.Darwin+=	-DBIND_8_COMPAT

post-configure:
	( cd ${WRKSRC} \
	  && grep '#define.*HAVE_SYS_QUEUE_H' config.h >/dev/null \
	  && mv missing/sys/queue.h missing/sys/queue.h.fake )

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
