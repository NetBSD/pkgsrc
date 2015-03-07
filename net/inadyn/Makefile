# $NetBSD: Makefile,v 1.8 2015/03/07 21:14:32 tnn Exp $

DISTNAME=	inadyn-1.96.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=troglobit/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://troglobit.com/inadyn.html
COMMENT=	Dynamic DNS client
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
RCD_SCRIPTS=	inadyn
RCD_SCRIPT_WRK.inadyn=	${WRKDIR}/inadyn.sh

LIBS.SunOS=	-lsocket -lnsl
MAKE_ENV+=	TARGET_ARCH=pkgsrc
MAKE_ENV+=	LIBS=${LIBS:Q}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

pre-patch:
	set -e && cd ${WRKSRC} &&  \
	for f in man/inadyn.conf.5 man/inadyn.8 src/dyndns.h ; do	\
		${SED}	-e "s|/etc|${PKG_SYSCONFDIR}|g"			\
			$${f} > $${f}.orig;			\
		${CP} -f $${f}.orig $${f};			\
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pkgsrc/inadyn ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/inadyn.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/man/inadyn.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
