# $NetBSD: Makefile,v 1.38 2017/09/06 10:40:32 wiz Exp $
#

DISTNAME=	xipdump-1.5.4
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.lse.epita.fr/twiki/pub/Projects/XipDump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.lse.epita.fr/twiki/bin/view/Projects/XipDump
COMMENT=	Displays IP packets using X Window System

PLIST_SRC=	${WRKDIR}/PLIST

GNU_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include
LIBS+=		-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib -lnet
LIBS.SunOS+=	-lsocket

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man8
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC}/data; ${FIND} pkc pkt ! -type d -print | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST_SRC})

post-install:
	${FIND} ${DESTDIR}${PREFIX}/share/xipdump -name *.pkc | \
		${XARGS} ${CHMOD} ${DOCMODE}
	${FIND} ${DESTDIR}${PREFIX}/share/xipdump -name *.pkt | \
		${XARGS} ${CHMOD} ${DOCMODE}
	${CHMOD} ${MANMODE} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/xipdump.8
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Xipdump

.include "../../devel/libnet10/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
